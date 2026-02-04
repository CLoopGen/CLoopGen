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

Atrac3pChanUnitCtx *ch_unit;
int num_channels = 2;
int ch;

static uint8_t global_wnd_shape_mem[2][2][16];
static AtracGainInfo global_gain_data_mem[2][2][16];
static Atrac3pWavesData global_tones_info_mem[2][2][16];

void init_vars() {
    ch_unit = (Atrac3pChanUnitCtx*)aligned_alloc(32, sizeof(Atrac3pChanUnitCtx));
    memset(ch_unit, 0, sizeof(Atrac3pChanUnitCtx));

    for (int c = 0; c < 2; c++) {
        ch_unit->channels[c].ch_num = c;
        ch_unit->channels[c].num_coded_vals = 32;
        ch_unit->channels[c].fill_mode = 0;
        ch_unit->channels[c].split_point = 16;
        ch_unit->channels[c].table_type = 1;
        for (int i = 0; i < 32; i++) {
            ch_unit->channels[c].qu_wordlen[i] = 4;
            ch_unit->channels[c].qu_sf_idx[i] = 8;
            ch_unit->channels[c].qu_tab_idx[i] = 1;
        }
        for (int i = 0; i < 2048; i++) {
            ch_unit->channels[c].spectrum[i] = (int16_t)(i % 256);
        }
        for (int i = 0; i < 5; i++) {
            ch_unit->channels[c].power_levs[i] = i + 1;
        }
        for (int h = 0; h < 2; h++) {
            for (int i = 0; i < 16; i++) {
                ch_unit->channels[c].wnd_shape_hist[h][i] = (h + c) * 16 + i;
            }
        }

        ch_unit->channels[c].wnd_shape = global_wnd_shape_mem[c][0];
        ch_unit->channels[c].wnd_shape_prev = global_wnd_shape_mem[c][1];

        for (int h = 0; h < 2; h++) {
            for (int i = 0; i < 16; i++) {
                ch_unit->channels[c].gain_data_hist[h][i].num_points = 3;
                for (int j = 0; j < 7; j++) {
                    ch_unit->channels[c].gain_data_hist[h][i].lev_code[j] = j % 4;
                    ch_unit->channels[c].gain_data_hist[h][i].loc_code[j] = (j + 1) % 5;
                }
            }
        }

        ch_unit->channels[c].gain_data = global_gain_data_mem[c][0];
        ch_unit->channels[c].gain_data_prev = global_gain_data_mem[c][1];

        for (int h = 0; h < 2; h++) {
            for (int i = 0; i < 16; i++) {
                ch_unit->channels[c].tones_info_hist[h][i].num_wavs = 1;
                ch_unit->channels[c].tones_info_hist[h][i].start_index = i * 3;
                memset(&ch_unit->channels[c].tones_info_hist[h][i].pend_env, 0, sizeof(Atrac3pWaveEnvelope));
                memset(&ch_unit->channels[c].tones_info_hist[h][i].curr_env, 0, sizeof(Atrac3pWaveEnvelope));
            }
        }

        ch_unit->channels[c].tones_info = global_tones_info_mem[c][0];
        ch_unit->channels[c].tones_info_prev = global_tones_info_mem[c][1];

        ch_unit->channels[c].num_gain_subbands = 8;
    }

    for (int i = 0; i < 2; i++) {
        ch_unit->wave_synth_hist[i].tones_present = 1;
        ch_unit->wave_synth_hist[i].amplitude_mode = i;
        ch_unit->wave_synth_hist[i].num_tone_bands = 8;
        for (int j = 0; j < 16; j++) {
            ch_unit->wave_synth_hist[i].tone_sharing[j] = j % 2;
            ch_unit->wave_synth_hist[i].tone_master[j] = j % 3;
            ch_unit->wave_synth_hist[i].invert_phase[j] = j % 2;
        }
        ch_unit->wave_synth_hist[i].tones_index = i * 10;
        for (int j = 0; j < 48; j++) {
            ch_unit->wave_synth_hist[i].waves[j].freq_index = j * 10;
            ch_unit->wave_synth_hist[i].waves[j].amp_sf = j % 5;
            ch_unit->wave_synth_hist[i].waves[j].amp_index = j % 8;
            ch_unit->wave_synth_hist[i].waves[j].phase_index = j % 4;
        }
    }

    ch_unit->waves_info = &ch_unit->wave_synth_hist[0];
    ch_unit->waves_info_prev = &ch_unit->wave_synth_hist[1];

    for (int c = 0; c < 2; c++) {
        ch_unit->ipqf_ctx[c].pos = 0;
        for (int i = 0; i < 24; i++) {
            for (int j = 0; j < 8; j++) {
                ch_unit->ipqf_ctx[c].buf1[i][j] = 0.1f * (i + j);
                ch_unit->ipqf_ctx[c].buf2[i][j] = 0.2f * (i + j);
            }
        }
        for (int i = 0; i < 2048; i++) {
            ch_unit->prev_buf[c][i] = 0.0f;
        }
    }

    ch_unit->unit_type = 0;
    ch_unit->num_quant_units = 32;
    ch_unit->num_subbands = 16;
    ch_unit->used_quant_units = 24;
    ch_unit->num_coded_subbands = 16;
    ch_unit->mute_flag = 0;
    ch_unit->use_full_table = 1;
    ch_unit->noise_present = 1;
    ch_unit->noise_level_index = 2;
    ch_unit->noise_table_index = 1;
    for (int i = 0; i < 16; i++) {
        ch_unit->swap_channels[i] = i % 2;
        ch_unit->negate_coeffs[i] = i % 2;
    }

    num_channels = 2;
}