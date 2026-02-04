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
int sb;
int RNG_index;
int sb_RNG_index[16];

void init_vars() {
    ch_unit = (Atrac3pChanUnitCtx*)aligned_alloc(32, sizeof(Atrac3pChanUnitCtx));
    
    ch_unit->num_coded_subbands = 16;
    RNG_index = 0;

    for (int i = 0; i < 2; i++) {
        ch_unit->channels[i].ch_num = i;
        ch_unit->channels[i].num_coded_vals = 2048;
        ch_unit->channels[i].num_gain_subbands = 8;
        ch_unit->channels[i].gain_data = ch_unit->channels[i].gain_data_hist[0];
        ch_unit->channels[i].gain_data_prev = ch_unit->channels[i].gain_data_hist[1];
        ch_unit->channels[i].tones_info = ch_unit->channels[i].tones_info_hist[0];
        ch_unit->channels[i].tones_info_prev = ch_unit->channels[i].tones_info_hist[1];
        ch_unit->channels[i].wnd_shape = ch_unit->channels[i].wnd_shape_hist[0];
        ch_unit->channels[i].wnd_shape_prev = ch_unit->channels[i].wnd_shape_hist[1];
        for (int j = 0; j < 32; j++) {
            ch_unit->channels[i].qu_wordlen[j] = 16;
            ch_unit->channels[i].qu_sf_idx[j] = 0;
            ch_unit->channels[i].qu_tab_idx[j] = 0;
        }
        for (int j = 0; j < 2048; j++) {
            ch_unit->channels[i].spectrum[j] = (int16_t)rand();
        }
        for (int j = 0; j < 5; j++) {
            ch_unit->channels[i].power_levs[j] = 128;
        }
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 16; k++) {
                ch_unit->channels[i].wnd_shape_hist[j][k] = 1;
                ch_unit->channels[i].gain_data_hist[j][k].num_points = 3;
                for (int l = 0; l < 7; l++) {
                    ch_unit->channels[i].gain_data_hist[j][k].lev_code[l] = 1;
                    ch_unit->channels[i].gain_data_hist[j][k].loc_code[l] = l * 2;
                }
                ch_unit->channels[i].tones_info_hist[j][k].num_wavs = 1;
                ch_unit->channels[i].tones_info_hist[j][k].start_index = 0;
                ch_unit->channels[i].tones_info_hist[j][k].pend_env.has_start_point = 1;
                ch_unit->channels[i].tones_info_hist[j][k].pend_env.has_stop_point = 1;
                ch_unit->channels[i].tones_info_hist[j][k].pend_env.start_pos = 0;
                ch_unit->channels[i].tones_info_hist[j][k].pend_env.stop_pos = 1024;
                ch_unit->channels[i].tones_info_hist[j][k].curr_env = ch_unit->channels[i].tones_info_hist[j][k].pend_env;
            }
        }
    }

    ch_unit->waves_info = &ch_unit->wave_synth_hist[0];
    ch_unit->waves_info_prev = &ch_unit->wave_synth_hist[1];
    for (int i = 0; i < 2; i++) {
        ch_unit->wave_synth_hist[i].tones_present = 1;
        ch_unit->wave_synth_hist[i].amplitude_mode = 0;
        ch_unit->wave_synth_hist[i].num_tone_bands = 8;
        ch_unit->wave_synth_hist[i].tones_index = i * 24;
        for (int j = 0; j < 16; j++) {
            ch_unit->wave_synth_hist[i].tone_sharing[j] = 1;
            ch_unit->wave_synth_hist[i].tone_master[j] = 0;
            ch_unit->wave_synth_hist[i].invert_phase[j] = 0;
        }
        for (int j = 0; j < 48; j++) {
            ch_unit->wave_synth_hist[i].waves[j].freq_index = j * 10;
            ch_unit->wave_synth_hist[i].waves[j].amp_sf = 3;
            ch_unit->wave_synth_hist[i].waves[j].amp_index = 15;
            ch_unit->wave_synth_hist[i].waves[j].phase_index = j;
        }
    }

    for (int i = 0; i < 2; i++) {
        ch_unit->ipqf_ctx[i].pos = 0;
        for (int j = 0; j < 24; j++) {
            for (int k = 0; k < 8; k++) {
                ch_unit->ipqf_ctx[i].buf1[j][k] = 0.0f;
                ch_unit->ipqf_ctx[i].buf2[j][k] = 0.0f;
            }
        }
        for (int j = 0; j < 2048; j++) {
            ch_unit->prev_buf[i][j] = 0.0f;
        }
    }

    for (int i = 0; i < 16; i++) {
        ch_unit->swap_channels[i] = i;
        ch_unit->negate_coeffs[i] = 0;
    }

    sb = 0;
    RNG_index = 0;
}