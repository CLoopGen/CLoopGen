#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct ATRAC9ChannelData {
    int band_ext;
    int q_unit_cnt;
    int band_ext_data[4];
    int32_t scalefactors[31];
    int32_t scalefactors_prev[31];
    int precision_coarse[30];
    int precision_fine[30];
    int precision_mask[30];
    int codebookset[30];
    int32_t q_coeffs_coarse[256];
    int32_t q_coeffs_fine[256];
    float coeffs[256] __attribute__((aligned(32)));
    float prev_win[128] __attribute__((aligned(32)));
} ATRAC9ChannelData;

typedef struct ATRAC9BlockData {
    ATRAC9ChannelData channel[2];
    int band_count;
    int q_unit_cnt;
    int q_unit_cnt_prev;
    int stereo_q_unit;
    int has_band_ext;
    int has_band_ext_data;
    int band_ext_q_unit;
    int grad_mode;
    int grad_boundary;
    int gradient[31];
    int cpe_base_channel;
    int is_signs[30];
    int reuseable;
} ATRAC9BlockData;

ATRAC9BlockData *b;
int grad_range[2];
int grad_value[2];

void init_vars() {
    b = (ATRAC9BlockData*)aligned_alloc(32, sizeof(ATRAC9BlockData));
    
    b->q_unit_cnt = 30;
    b->grad_mode = 0;
    b->grad_boundary = 0;
    b->has_band_ext = 0;
    b->has_band_ext_data = 0;
    b->band_ext_q_unit = 0;
    b->stereo_q_unit = 0;
    b->band_count = 1;
    b->cpe_base_channel = 0;
    b->reuseable = 1;
    b->q_unit_cnt_prev = 0;

    for (int i = 0; i < 31; i++) {
        b->gradient[i] = 0;
    }

    for (int i = 0; i < 30; i++) {
        b->is_signs[i] = 0;
    }

    for (int ch_idx = 0; ch_idx < 2; ch_idx++) {
        ATRAC9ChannelData *ch = &b->channel[ch_idx];
        ch->band_ext = 0;
        ch->q_unit_cnt = 0;
        for (int i = 0; i < 4; i++)
            ch->band_ext_data[i] = 0;
        for (int i = 0; i < 31; i++) {
            ch->scalefactors[i] = 0;
            ch->scalefactors_prev[i] = 0;
        }
        for (int i = 0; i < 30; i++) {
            ch->precision_coarse[i] = 0;
            ch->precision_fine[i] = 0;
            ch->precision_mask[i] = 0;
            ch->codebookset[i] = 0;
        }
        for (int i = 0; i < 256; i++) {
            ch->q_coeffs_coarse[i] = 0;
            ch->q_coeffs_fine[i] = 0;
            ch->coeffs[i] = 0.0f;
        }
        for (int i = 0; i < 128; i++) {
            ch->prev_win[i] = 0.0f;
        }
    }

    grad_range[0] = 15;
    grad_range[1] = 30;
    grad_value[0] = 100;
    grad_value[1] = 200;
}