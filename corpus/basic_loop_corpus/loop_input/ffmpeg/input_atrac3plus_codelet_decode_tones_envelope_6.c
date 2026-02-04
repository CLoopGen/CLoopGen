#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

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

Atrac3pChanUnitCtx *ctx;
int band_has_tones[256];
int sb;
Atrac3pWavesData *dst;
Atrac3pWavesData *ref;

void init_vars() {
    const int data_size = 256;
    ctx = (Atrac3pChanUnitCtx*)aligned_alloc(32, sizeof(Atrac3pChanUnitCtx));
    memset(ctx, 0, sizeof(Atrac3pChanUnitCtx));

    ctx->waves_info = (Atrac3pWaveSynthParams*)aligned_alloc(32, sizeof(Atrac3pWaveSynthParams));
    memset(ctx->waves_info, 0, sizeof(Atrac3pWaveSynthParams));
    ctx->waves_info->num_tone_bands = data_size;

    dst = (Atrac3pWavesData*)aligned_alloc(32, data_size * sizeof(Atrac3pWavesData));
    ref = (Atrac3pWavesData*)aligned_alloc(32, data_size * sizeof(Atrac3pWavesData));

    for (int i = 0; i < data_size; i++) {
        ref[i].pend_env.has_start_point = i % 2;
        ref[i].pend_env.has_stop_point = (i + 1) % 2;
        ref[i].pend_env.start_pos = i * 10;
        ref[i].pend_env.stop_pos = i * 20;
    }

    for (int i = 0; i < data_size; i++) {
        band_has_tones[i] = (i % 3 == 0);
    }

    sb = 0;
}