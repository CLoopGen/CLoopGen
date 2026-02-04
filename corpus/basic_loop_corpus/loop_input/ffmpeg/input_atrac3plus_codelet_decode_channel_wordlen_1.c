#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
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

int i;
int pos;
Atrac3pChanParams *chan;

void init_vars() {
    chan = (Atrac3pChanParams*)calloc(1, sizeof(Atrac3pChanParams));
    if (!chan) exit(1);

    chan->num_coded_vals = 0;
    pos = 32;

    for (int j = 0; j < 32; j++) {
        chan->qu_wordlen[j] = 0;
        chan->qu_sf_idx[j] = 0;
        chan->qu_tab_idx[j] = 0;
    }

    for (int j = 0; j < 2048; j++) {
        chan->spectrum[j] = 0;
    }

    for (int j = 0; j < 5; j++) {
        chan->power_levs[j] = 0;
    }

    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 16; k++) {
            chan->wnd_shape_hist[j][k] = 0;
        }
    }

    chan->wnd_shape = calloc(16, sizeof(uint8_t));
    chan->wnd_shape_prev = calloc(16, sizeof(uint8_t));
    if (!chan->wnd_shape || !chan->wnd_shape_prev) exit(1);

    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 16; k++) {
            AtracGainInfo* g = &chan->gain_data_hist[j][k];
            g->num_points = 0;
            for (int m = 0; m < 7; m++) {
                g->lev_code[m] = 0;
                g->loc_code[m] = 0;
            }
        }
    }

    chan->gain_data = &chan->gain_data_hist[0][0];
    chan->gain_data_prev = &chan->gain_data_hist[1][0];

    chan->num_gain_subbands = 0;

    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 16; k++) {
            Atrac3pWavesData* w = &chan->tones_info_hist[j][k];
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

    chan->tones_info = &chan->tones_info_hist[0][0];
    chan->tones_info_prev = &chan->tones_info_hist[1][0];
}