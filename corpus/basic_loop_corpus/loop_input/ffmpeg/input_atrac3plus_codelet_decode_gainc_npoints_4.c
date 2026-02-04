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

int coded_subbands = 128;
int i;

Atrac3pChanParams *chan;
Atrac3pChanParams *ref_chan;

static AtracGainInfo *alloc_gain_data_array(int n) {
    AtracGainInfo *arr = (AtracGainInfo*)calloc(n, sizeof(AtracGainInfo));
    for (int i = 0; i < n; i++) {
        arr[i].num_points = i % 8;
        for (int j = 0; j < 7; j++) {
            arr[i].lev_code[j] = (i + j) % 16;
            arr[i].loc_code[j] = (i * j) % 32;
        }
    }
    return arr;
}

void init_vars() {
    chan = (Atrac3pChanParams*)calloc(1, sizeof(Atrac3pChanParams));
    ref_chan = (Atrac3pChanParams*)calloc(1, sizeof(Atrac3pChanParams));

    chan->gain_data = alloc_gain_data_array(coded_subbands);
    ref_chan->gain_data = alloc_gain_data_array(coded_subbands);

    chan->num_gain_subbands = coded_subbands;
    ref_chan->num_gain_subbands = coded_subbands;
}