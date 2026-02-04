#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

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
int band_has_tones[16];
int sb;
int j;
int i;
int diff;
int maxdiff;
int fi;
Atrac3pWaveParam *wsrc;
Atrac3pWaveParam *wref;
int refwaves[48];
Atrac3pWavesData *dst;
Atrac3pWavesData *ref;

static Atrac3pChanUnitCtx g_ctx;
static Atrac3pWaveSynthParams g_wave_synth_params;
static Atrac3pWavesData g_dst_array[16];
static Atrac3pWavesData g_ref_array[16];

void init_vars() {
    ctx = &g_ctx;
    ctx->waves_info = &g_wave_synth_params;
    ctx->waves_info->num_tone_bands = 8;
    ctx->waves_info->tones_present = 1;
    ctx->waves_info->amplitude_mode = 0;
    ctx->waves_info->tones_index = 0;
    memset(ctx->waves_info->tone_sharing, 0, sizeof(ctx->waves_info->tone_sharing));
    memset(ctx->waves_info->tone_master, 0, sizeof(ctx->waves_info->tone_master));
    memset(ctx->waves_info->invert_phase, 0, sizeof(ctx->waves_info->invert_phase));

    dst = g_dst_array;
    ref = g_ref_array;

    for (int b = 0; b < 8; b++) {
        band_has_tones[b] = 1;
        
        g_dst_array[b].num_wavs = 4;
        g_dst_array[b].start_index = b * 6;
        g_ref_array[b].num_wavs = 4;
        g_ref_array[b].start_index = b * 6;

        g_dst_array[b].pend_env.has_start_point = 1;
        g_dst_array[b].pend_env.has_stop_point = 1;
        g_dst_array[b].pend_env.start_pos = b * 100;
        g_dst_array[b].pend_env.stop_pos = b * 100 + 50;
        g_dst_array[b].curr_env = g_dst_array[b].pend_env;

        g_ref_array[b].pend_env.has_start_point = 1;
        g_ref_array[b].pend_env.has_stop_point = 1;
        g_ref_array[b].pend_env.start_pos = b * 100;
        g_ref_array[b].pend_env.stop_pos = b * 100 + 50;
        g_ref_array[b].curr_env = g_ref_array[b].pend_env;
    }

    wsrc = &ctx->waves_info->waves[0];
    wref = &ctx->waves_info->waves[0];

    for (int idx = 0; idx < 48; idx++) {
        ctx->waves_info->waves[idx].freq_index = (idx * 17) % 1024;
        ctx->waves_info->waves[idx].amp_sf = (idx * 3) % 8;
        ctx->waves_info->waves[idx].amp_index = (idx * 5) % 32;
        ctx->waves_info->waves[idx].phase_index = (idx * 7) % 16;
    }

    memset(refwaves, -1, sizeof(refwaves));
}