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
float out[2][2048];
int i;
int sb;

void init_vars() {
    ch_unit = (Atrac3pChanUnitCtx*)aligned_alloc(32, sizeof(Atrac3pChanUnitCtx));
    if (!ch_unit) exit(1);

    memset(ch_unit, 0, sizeof(Atrac3pChanUnitCtx));

    ch_unit->num_coded_subbands = 16;
    for (int idx = 0; idx < 16; idx++) {
        ch_unit->swap_channels[idx] = (idx % 7 == 0);
        ch_unit->negate_coeffs[idx] = (idx % 5 == 0);
    }

    for (int c = 0; c < 2; c++) {
        for (int s = 0; s < 2048; s++) {
            out[c][s] = (float)(c * 2048 + s);
        }
    }

    ch_unit->waves_info = &ch_unit->wave_synth_hist[0];
    ch_unit->waves_info_prev = &ch_unit->wave_synth_hist[1];

    for (int c = 0; c < 2; c++) {
        ch_unit->channels[c].ch_num = c;
        ch_unit->channels[c].num_coded_vals = 2048;
        ch_unit->channels[c].num_gain_subbands = 8;
        ch_unit->channels[c].gain_data = ch_unit->channels[c].gain_data_hist[0];
        ch_unit->channels[c].gain_data_prev = ch_unit->channels[c].gain_data_hist[1];
        ch_unit->channels[c].tones_info = ch_unit->channels[c].tones_info_hist[0];
        ch_unit->channels[c].tones_info_prev = ch_unit->channels[c].tones_info_hist[1];
        ch_unit->channels[c].wnd_shape = ch_unit->channels[c].wnd_shape_hist[0];
        ch_unit->channels[c].wnd_shape_prev = ch_unit->channels[c].wnd_shape_hist[1];
    }

    for (int w = 0; w < 2; w++) {
        ch_unit->wave_synth_hist[w].tones_present = 1;
        ch_unit->wave_synth_hist[w].amplitude_mode = w;
        ch_unit->wave_synth_hist[w].num_tone_bands = 8;
        ch_unit->wave_synth_hist[w].tones_index = w * 24;
        for (int t = 0; t < 16; t++) {
            ch_unit->wave_synth_hist[w].tone_sharing[t] = t % 2;
            ch_unit->wave_synth_hist[w].tone_master[t] = t % 3;
            ch_unit->wave_synth_hist[w].invert_phase[t] = t % 2;
        }
        for (int p = 0; p < 48; p++) {
            ch_unit->wave_synth_hist[w].waves[p].freq_index = p * 10;
            ch_unit->wave_synth_hist[w].waves[p].amp_sf = p % 5;
            ch_unit->wave_synth_hist[w].waves[p].amp_index = p * 2;
            ch_unit->wave_synth_hist[w].waves[p].phase_index = p % 7;
        }
    }

    for (int c = 0; c < 2; c++) {
        for (int h = 0; h < 2; h++) {
            for (int g = 0; g < 16; g++) {
                ch_unit->channels[c].gain_data_hist[h][g].num_points = g % 4;
                for (int l = 0; l < 7; l++) {
                    ch_unit->channels[c].gain_data_hist[h][g].lev_code[l] = l % 3;
                    ch_unit->channels[c].gain_data_hist[h][g].loc_code[l] = (l + h) % 5;
                }
            }
            for (int t = 0; t < 16; t++) {
                ch_unit->channels[c].tones_info_hist[h][t].num_wavs = t % 5;
                ch_unit->channels[c].tones_info_hist[h][t].start_index = t * 3;
                ch_unit->channels[c].tones_info_hist[h][t].pend_env.has_start_point = h;
                ch_unit->channels[c].tones_info_hist[h][t].pend_env.has_stop_point = h ^ 1;
                ch_unit->channels[c].tones_info_hist[h][t].pend_env.start_pos = t * 10;
                ch_unit->channels[c].tones_info_hist[h][t].pend_env.stop_pos = t * 10 + 5;
                ch_unit->channels[c].tones_info_hist[h][t].curr_env = ch_unit->channels[c].tones_info_hist[h][t].pend_env;
            }
            for (int w = 0; w < 16; w++) {
                ch_unit->channels[c].wnd_shape_hist[h][w] = w % 8;
            }
        }
        for (int q = 0; q < 32; q++) {
            ch_unit->channels[c].qu_wordlen[q] = q % 6;
            ch_unit->channels[c].qu_sf_idx[q] = q % 4;
            ch_unit->channels[c].qu_tab_idx[q] = q % 2;
        }
        for (int s = 0; s < 2048; s++) {
            ch_unit->channels[c].spectrum[s] = s % 256;
        }
        for (int p = 0; p < 5; p++) {
            ch_unit->channels[c].power_levs[p] = p * 10;
        }
    }

    for (int c = 0; c < 2; c++) {
        ch_unit->ipqf_ctx[c].pos = c * 12;
        for (int b1 = 0; b1 < 24; b1++) {
            for (int b2 = 0; b2 < 8; b2++) {
                ch_unit->ipqf_ctx[c].buf1[b1][b2] = (float)(c * 100 + b1 * 8 + b2);
                ch_unit->ipqf_ctx[c].buf2[b1][b2] = (float)(c * 200 + b1 * 8 + b2);
            }
        }
    }

    for (int c = 0; c < 2; c++) {
        for (int s = 0; s < 2048; s++) {
            ch_unit->prev_buf[c][s] = (float)(c * 3000 + s);
        }
    }
}