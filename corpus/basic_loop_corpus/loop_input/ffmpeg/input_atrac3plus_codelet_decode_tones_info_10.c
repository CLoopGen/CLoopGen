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
int i;

static Atrac3pWaveSynthParams g_waves_info;
static Atrac3pWavesData g_tones_info_ch0[16];
static Atrac3pWavesData g_tones_info_ch1[16];

void init_vars() {
    ctx = (Atrac3pChanUnitCtx*)aligned_alloc(32, sizeof(Atrac3pChanUnitCtx));
    
    ctx->unit_type = 0;
    ctx->num_quant_units = 0;
    ctx->num_subbands = 0;
    ctx->used_quant_units = 0;
    ctx->num_coded_subbands = 0;
    ctx->mute_flag = 0;
    ctx->use_full_table = 0;
    ctx->noise_present = 0;
    ctx->noise_level_index = 0;
    ctx->noise_table_index = 0;
    for (int j = 0; j < 16; j++) {
        ctx->swap_channels[j] = 0;
        ctx->negate_coeffs[j] = 0;
    }

    for (int ch = 0; ch < 2; ch++) {
        ctx->channels[ch].ch_num = ch;
        ctx->channels[ch].num_coded_vals = 0;
        ctx->channels[ch].fill_mode = 0;
        ctx->channels[ch].split_point = 0;
        ctx->channels[ch].table_type = 0;
        for (int j = 0; j < 32; j++) {
            ctx->channels[ch].qu_wordlen[j] = 0;
            ctx->channels[ch].qu_sf_idx[j] = 0;
            ctx->channels[ch].qu_tab_idx[j] = 0;
        }
        for (int j = 0; j < 2048; j++) {
            ctx->channels[ch].spectrum[j] = 0;
        }
        for (int j = 0; j < 5; j++) {
            ctx->channels[ch].power_levs[j] = 0;
        }
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < 16; j++) {
                ctx->channels[ch].wnd_shape_hist[k][j] = 0;
            }
        }
        ctx->channels[ch].wnd_shape = NULL;
        ctx->channels[ch].wnd_shape_prev = NULL;
        for (int h = 0; h < 2; h++) {
            for (int j = 0; j < 16; j++) {
                ctx->channels[ch].gain_data_hist[h][j].num_points = 0;
                for (int p = 0; p < 7; p++) {
                    ctx->channels[ch].gain_data_hist[h][j].lev_code[p] = 0;
                    ctx->channels[ch].gain_data_hist[h][j].loc_code[p] = 0;
                }
            }
        }
        ctx->channels[ch].gain_data = NULL;
        ctx->channels[ch].gain_data_prev = NULL;
        ctx->channels[ch].num_gain_subbands = 0;
        for (int h = 0; h < 2; h++) {
            for (int j = 0; j < 16; j++) {
                ctx->channels[ch].tones_info_hist[h][j].pend_env.has_start_point = 0;
                ctx->channels[ch].tones_info_hist[h][j].pend_env.has_stop_point = 0;
                ctx->channels[ch].tones_info_hist[h][j].pend_env.start_pos = 0;
                ctx->channels[ch].tones_info_hist[h][j].pend_env.stop_pos = 0;
                ctx->channels[ch].tones_info_hist[h][j].curr_env.has_start_point = 0;
                ctx->channels[ch].tones_info_hist[h][j].curr_env.has_stop_point = 0;
                ctx->channels[ch].tones_info_hist[h][j].curr_env.start_pos = 0;
                ctx->channels[ch].tones_info_hist[h][j].curr_env.stop_pos = 0;
                ctx->channels[ch].tones_info_hist[h][j].num_wavs = 0;
                ctx->channels[ch].tones_info_hist[h][j].start_index = 0;
            }
        }
    }

    ctx->waves_info = &g_waves_info;
    ctx->waves_info_prev = NULL;

    g_waves_info.tones_present = 1;
    g_waves_info.amplitude_mode = 0;
    g_waves_info.num_tone_bands = 16;
    for (int j = 0; j < 16; j++) {
        g_waves_info.tone_sharing[j] = (j % 2);
        g_waves_info.tone_master[j] = (j % 3 == 0);
        g_waves_info.invert_phase[j] = 0;
    }
    g_waves_info.tones_index = 0;
    for (int j = 0; j < 48; j++) {
        g_waves_info.waves[j].freq_index = 0;
        g_waves_info.waves[j].amp_sf = 0;
        g_waves_info.waves[j].amp_index = 0;
        g_waves_info.waves[j].phase_index = 0;
    }

    for (int j = 0; j < 16; j++) {
        g_tones_info_ch0[j].pend_env.has_start_point = 1;
        g_tones_info_ch0[j].pend_env.has_stop_point = 1;
        g_tones_info_ch0[j].pend_env.start_pos = j * 100;
        g_tones_info_ch0[j].pend_env.stop_pos = j * 100 + 50;
        g_tones_info_ch0[j].curr_env.has_start_point = 1;
        g_tones_info_ch0[j].curr_env.has_stop_point = 1;
        g_tones_info_ch0[j].curr_env.start_pos = j * 100 + 10;
        g_tones_info_ch0[j].curr_env.stop_pos = j * 100 + 60;
        g_tones_info_ch0[j].num_wavs = j + 1;
        g_tones_info_ch0[j].start_index = j * 10;

        g_tones_info_ch1[j].pend_env.has_start_point = 1;
        g_tones_info_ch1[j].pend_env.has_stop_point = 1;
        g_tones_info_ch1[j].pend_env.start_pos = j * 150;
        g_tones_info_ch1[j].pend_env.stop_pos = j * 150 + 50;
        g_tones_info_ch1[j].curr_env.has_start_point = 1;
        g_tones_info_ch1[j].curr_env.has_stop_point = 1;
        g_tones_info_ch1[j].curr_env.start_pos = j * 150 + 10;
        g_tones_info_ch1[j].curr_env.stop_pos = j * 150 + 60;
        g_tones_info_ch1[j].num_wavs = j + 2;
        g_tones_info_ch1[j].start_index = j * 15;
    }

    ctx->channels[0].tones_info = g_tones_info_ch0;
    ctx->channels[1].tones_info = g_tones_info_ch1;
    ctx->channels[0].tones_info_prev = NULL;
    ctx->channels[1].tones_info_prev = NULL;

    for (int j = 0; j < 2; j++) {
        ctx->wave_synth_hist[j].tones_present = 1;
        ctx->wave_synth_hist[j].amplitude_mode = 0;
        ctx->wave_synth_hist[j].num_tone_bands = 16;
        for (int k = 0; k < 16; k++) {
            ctx->wave_synth_hist[j].tone_sharing[k] = (k % 2);
            ctx->wave_synth_hist[j].tone_master[k] = (k % 3 == 0);
            ctx->wave_synth_hist[j].invert_phase[k] = 0;
        }
        ctx->wave_synth_hist[j].tones_index = 0;
        for (int k = 0; k < 48; k++) {
            ctx->wave_synth_hist[j].waves[k].freq_index = 0;
            ctx->wave_synth_hist[j].waves[k].amp_sf = 0;
            ctx->wave_synth_hist[j].waves[k].amp_index = 0;
            ctx->wave_synth_hist[j].waves[k].phase_index = 0;
        }
    }

    for (int ch = 0; ch < 2; ch++) {
        for (int b = 0; b < 24; b++) {
            for (int s = 0; s < 8; s++) {
                ctx->ipqf_ctx[ch].buf1[b][s] = 0.0f;
                ctx->ipqf_ctx[ch].buf2[b][s] = 0.0f;
            }
        }
        ctx->ipqf_ctx[ch].pos = 0;
    }

    for (int ch = 0; ch < 2; ch++) {
        for (int j = 0; j < 2048; j++) {
            ctx->prev_buf[ch][j] = 0.0f;
        }
    }
}