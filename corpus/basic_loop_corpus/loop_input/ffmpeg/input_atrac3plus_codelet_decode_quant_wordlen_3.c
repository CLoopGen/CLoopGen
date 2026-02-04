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

Atrac3pChanUnitCtx *ctx;
int num_channels = 2;
int i;

static Atrac3pChanUnitCtx g_ctx_instance;

void init_vars() {
    ctx = &g_ctx_instance;

    ctx->num_quant_units = 32;
    ctx->num_subbands = 16;
    ctx->used_quant_units = 0;
    ctx->num_coded_subbands = 16;
    ctx->mute_flag = 0;
    ctx->use_full_table = 1;
    ctx->noise_present = 0;
    ctx->noise_level_index = 0;
    ctx->noise_table_index = 0;
    for (int j = 0; j < 16; j++) {
        ctx->swap_channels[j] = 0;
        ctx->negate_coeffs[j] = 0;
    }

    for (int ch = 0; ch < 2; ch++) {
        Atrac3pChanParams *chan = &ctx->channels[ch];
        chan->ch_num = ch;
        chan->num_coded_vals = 1024;
        chan->fill_mode = 0;
        chan->split_point = 8;
        chan->table_type = 0;
        for (int j = 0; j < 32; j++) {
            chan->qu_wordlen[j] = (j < 16) ? (j % 5 + 1) : 0;
            chan->qu_sf_idx[j] = 0;
            chan->qu_tab_idx[j] = 0;
        }
        for (int j = 0; j < 2048; j++) {
            chan->spectrum[j] = 0;
        }
        for (int j = 0; j < 5; j++) {
            chan->power_levs[j] = 0;
        }
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < 16; j++) {
                chan->wnd_shape_hist[k][j] = 0;
            }
        }
        chan->wnd_shape = NULL;
        chan->wnd_shape_prev = NULL;
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < 16; j++) {
                AtracGainInfo *gain = &chan->gain_data_hist[k][j];
                gain->num_points = 0;
                for (int m = 0; m < 7; m++) {
                    gain->lev_code[m] = 0;
                    gain->loc_code[m] = 0;
                }
            }
        }
        chan->gain_data = NULL;
        chan->gain_data_prev = NULL;
        chan->num_gain_subbands = 0;
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < 16; j++) {
                Atrac3pWavesData *wave_data = &chan->tones_info_hist[k][j];
                wave_data->pend_env.has_start_point = 0;
                wave_data->pend_env.has_stop_point = 0;
                wave_data->pend_env.start_pos = 0;
                wave_data->pend_env.stop_pos = 0;
                wave_data->curr_env.has_start_point = 0;
                wave_data->curr_env.has_stop_point = 0;
                wave_data->curr_env.start_pos = 0;
                wave_data->curr_env.stop_pos = 0;
                wave_data->num_wavs = 0;
                wave_data->start_index = 0;
            }
        }
        chan->tones_info = NULL;
        chan->tones_info_prev = NULL;
    }

    for (int j = 0; j < 2; j++) {
        Atrac3pWaveSynthParams *wsp = &ctx->wave_synth_hist[j];
        wsp->tones_present = 0;
        wsp->amplitude_mode = 0;
        wsp->num_tone_bands = 0;
        for (int k = 0; k < 16; k++) {
            wsp->tone_sharing[k] = 0;
            wsp->tone_master[k] = 0;
            wsp->invert_phase[k] = 0;
        }
        wsp->tones_index = 0;
        for (int k = 0; k < 48; k++) {
            wsp->waves[k].freq_index = 0;
            wsp->waves[k].amp_sf = 0;
            wsp->waves[k].amp_index = 0;
            wsp->waves[k].phase_index = 0;
        }
    }
    ctx->waves_info = NULL;
    ctx->waves_info_prev = NULL;

    for (int ch = 0; ch < 2; ch++) {
        Atrac3pIPQFChannelCtx *ipqf = &ctx->ipqf_ctx[ch];
        ipqf->pos = 0;
        for (int j = 0; j < 24; j++) {
            for (int k = 0; k < 8; k++) {
                ipqf->buf1[j][k] = 0.0f;
                ipqf->buf2[j][k] = 0.0f;
            }
        }
    }

    for (int ch = 0; ch < 2; ch++) {
        for (int j = 0; j < 2048; j++) {
            ctx->prev_buf[ch][j] = 0.0f;
        }
    }

    num_channels = 2;
}