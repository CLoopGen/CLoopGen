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

Atrac3pChanUnitCtx *ch_unit;
int qu;
int RNG_index;

void init_vars() {
    ch_unit = (Atrac3pChanUnitCtx*)aligned_alloc(32, sizeof(Atrac3pChanUnitCtx));
    
    ch_unit->unit_type = 0;
    ch_unit->num_quant_units = 32;
    ch_unit->num_subbands = 16;
    ch_unit->used_quant_units = 20; // Ensures loop runs 20 times: safe for qu_sf_idx[32]
    ch_unit->num_coded_subbands = 16;
    ch_unit->mute_flag = 0;
    ch_unit->use_full_table = 1;
    ch_unit->noise_present = 0;
    ch_unit->noise_level_index = 0;
    ch_unit->noise_table_index = 0;
    for (int i = 0; i < 16; i++) {
        ch_unit->swap_channels[i] = 0;
        ch_unit->negate_coeffs[i] = 0;
    }
    
    for (int c = 0; c < 2; c++) {
        Atrac3pChanParams *chan = &ch_unit->channels[c];
        chan->ch_num = c;
        chan->num_coded_vals = 2048;
        chan->fill_mode = 0;
        chan->split_point = 0;
        chan->table_type = 0;
        for (int i = 0; i < 32; i++) {
            chan->qu_wordlen[i] = 1;
            chan->qu_sf_idx[i] = (i < ch_unit->used_quant_units) ? (i % 8) : 0;
            chan->qu_tab_idx[i] = 0;
        }
        for (int i = 0; i < 2048; i++) {
            chan->spectrum[i] = 0;
        }
        for (int i = 0; i < 5; i++) {
            chan->power_levs[i] = 0;
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 16; j++) {
                chan->wnd_shape_hist[i][j] = 0;
            }
        }
        chan->wnd_shape = NULL;
        chan->wnd_shape_prev = NULL;
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 16; j++) {
                AtracGainInfo *g = &chan->gain_data_hist[i][j];
                g->num_points = 0;
                for (int k = 0; k < 7; k++) {
                    g->lev_code[k] = 0;
                    g->loc_code[k] = 0;
                }
            }
        }
        chan->gain_data = NULL;
        chan->gain_data_prev = NULL;
        chan->num_gain_subbands = 0;
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 16; j++) {
                Atrac3pWavesData *w = &chan->tones_info_hist[i][j];
                w->pend_env.has_start_point = 0;
                w->pend_env.has_stop_point = 0;
                w->pend_env.start_pos = 0;
                w->pend_env.stop_pos = 0;
                w->curr_env.has_start_point = 0;
                w->curr_env.has_stop_point = 0;
                w->curr_env.start_pos = 0;
                w->curr_env.stop_pos = 0;
                w->num_wavs = 0;
                w->start_index = 0;
            }
        }
        chan->tones_info = NULL;
        chan->tones_info_prev = NULL;
    }
    
    for (int i = 0; i < 2; i++) {
        Atrac3pWaveSynthParams *w = &ch_unit->wave_synth_hist[i];
        w->tones_present = 0;
        w->amplitude_mode = 0;
        w->num_tone_bands = 0;
        for (int j = 0; j < 16; j++) {
            w->tone_sharing[j] = 0;
            w->tone_master[j] = 0;
            w->invert_phase[j] = 0;
        }
        w->tones_index = 0;
        for (int j = 0; j < 48; j++) {
            w->waves[j].freq_index = 0;
            w->waves[j].amp_sf = 0;
            w->waves[j].amp_index = 0;
            w->waves[j].phase_index = 0;
        }
    }
    ch_unit->waves_info = NULL;
    ch_unit->waves_info_prev = NULL;
    
    for (int i = 0; i < 2; i++) {
        Atrac3pIPQFChannelCtx *ctx = &ch_unit->ipqf_ctx[i];
        ctx->pos = 0;
        for (int j = 0; j < 24; j++) {
            for (int k = 0; k < 8; k++) {
                ctx->buf1[j][k] = 0.0f;
                ctx->buf2[j][k] = 0.0f;
            }
        }
        for (int j = 0; j < 2048; j++) {
            ch_unit->prev_buf[i][j] = 0.0f;
        }
    }
    
    qu = 0;
    RNG_index = 0;
}