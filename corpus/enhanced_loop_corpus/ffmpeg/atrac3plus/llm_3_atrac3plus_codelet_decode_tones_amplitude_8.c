#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AtracGainInfo {
    int num_points;
    int lev_code[7];
    int loc_code[7];
} AtracGainInfo;

typedef struct Atrac3pWaveEnvelope {
    int has_start_point;
    int has_stop_point;
    int start_pos;
    int stop_pos;
} Atrac3pWaveEnvelope;

typedef struct Atrac3pWavesData {
    Atrac3pWaveEnvelope pend_env;
    Atrac3pWaveEnvelope curr_env;
    int num_wavs;
    int start_index;
} Atrac3pWavesData;

typedef struct Atrac3pChanParams {
    int ch_num;
    int num_coded_vals;
    int fill_mode;
    int split_point;
    int table_type;
    int qu_wordlen[32];
    int qu_sf_idx[32];
    int qu_tab_idx[32];
    int16_t spectrum[2048];
    uint8_t power_levs[5];
    uint8_t wnd_shape_hist[2][16];
    uint8_t *wnd_shape;
    uint8_t *wnd_shape_prev;
    AtracGainInfo gain_data_hist[2][16];
    AtracGainInfo *gain_data;
    AtracGainInfo *gain_data_prev;
    int num_gain_subbands;
    Atrac3pWavesData tones_info_hist[2][16];
    Atrac3pWavesData *tones_info;
    Atrac3pWavesData *tones_info_prev;
} Atrac3pChanParams;

typedef struct Atrac3pWaveParam {
    int freq_index;
    int amp_sf;
    int amp_index;
    int phase_index;
} Atrac3pWaveParam;

typedef struct Atrac3pWaveSynthParams {
    int tones_present;
    int amplitude_mode;
    int num_tone_bands;
    uint8_t tone_sharing[16];
    uint8_t tone_master[16];
    uint8_t invert_phase[16];
    int tones_index;
    Atrac3pWaveParam waves[48];
} Atrac3pWaveSynthParams;

typedef struct Atrac3pIPQFChannelCtx {
    float buf1[24][8] __attribute__((aligned(32)));
    float buf2[24][8] __attribute__((aligned(32)));
    int pos;
} Atrac3pIPQFChannelCtx;

typedef struct Atrac3pChanUnitCtx {
    int unit_type;
    int num_quant_units;
    int num_subbands;
    int used_quant_units;
    int num_coded_subbands;
    int mute_flag;
    int use_full_table;
    int noise_present;
    int noise_level_index;
    int noise_table_index;
    uint8_t swap_channels[16];
    uint8_t negate_coeffs[16];
    Atrac3pChanParams channels[2];
    Atrac3pWaveSynthParams wave_synth_hist[2];
    Atrac3pWaveSynthParams *waves_info;
    Atrac3pWaveSynthParams *waves_info_prev;
    Atrac3pIPQFChannelCtx ipqf_ctx[2];
    float prev_buf[2][2048] __attribute__((aligned(32)));
} Atrac3pChanUnitCtx;

extern Atrac3pChanUnitCtx *ctx;
extern int band_has_tones[];
extern int sb;
extern int j;
extern int i;
extern int diff;
extern int maxdiff;
extern int fi;
extern Atrac3pWaveParam *wsrc;
extern Atrac3pWaveParam *wref;
extern int refwaves[48];
extern Atrac3pWavesData *dst;
extern Atrac3pWavesData *ref;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (sb = 0; sb < ctx->waves_info->num_tone_bands; sb++) {
        if (!band_has_tones[sb] || !dst[sb].num_wavs)
            continue;
        int dst_idx = dst[sb].start_index;
        int ref_idx = ref[sb].start_index;
        int *refwave_ptr = &refwaves[dst_idx]; // Consecutive output write via pointer
        const int max_wavs = dst[sb].num_wavs;
        const int ref_num_wavs = ref[sb].num_wavs;
        // Prefetch wave parameter base addresses to simulate indirect but structured access
        Atrac3pWaveParam *base_src = &ctx->waves_info->waves[0];
        Atrac3pWaveParam *base_ref = &ctx->waves_info->waves[0];
        for (j = 0; j < max_wavs; j++) {
            int src_freq = base_src[dst_idx + j].freq_index; // Indirect indexing with offset
            int closest_index = -1;
            int min_distance = 1024;
            // Strided read across reference waves
            for (i = 0; i < ref_num_wavs; i++) {
                int ref_freq = base_ref[ref_idx + i].freq_index;
                diff = abs(src_freq - ref_freq);
                if (diff < min_distance) {
                    min_distance = diff;
                    closest_index = i;
                }
            }
            if (min_distance < 8)
                refwave_ptr[j] = closest_index + ref_idx;
            else if (j < ref_num_wavs)
                refwave_ptr[j] = j + ref_idx;
            else
                refwave_ptr[j] = -1;
        }
    }
}
