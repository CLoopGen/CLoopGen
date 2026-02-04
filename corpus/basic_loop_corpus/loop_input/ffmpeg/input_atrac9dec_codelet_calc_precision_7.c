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
ATRAC9ChannelData *c;

void init_vars() {
    b = (ATRAC9BlockData*)aligned_alloc(32, sizeof(ATRAC9BlockData));
    c = &b->channel[0];

    b->q_unit_cnt = 30;

    for (int i = 0; i < 31; i++) {
        b->gradient[i] = 1 + (i % 5);
        if (i < 30) {
            c->scalefactors[i] = 10 + (i % 8);
        }
    }

    for (int i = 30; i < 31; i++) {
        c->scalefactors[i] = 0;
    }

    for (int i = 0; i < 30; i++) {
        c->precision_coarse[i] = 0;
        c->precision_fine[i] = 0;
        c->precision_mask[i] = 0;
        c->codebookset[i] = 0;
    }

    for (int i = 0; i < 256; i++) {
        c->q_coeffs_coarse[i] = 0;
        c->q_coeffs_fine[i] = 0;
        c->coeffs[i] = 0.0f;
    }

    for (int i = 0; i < 128; i++) {
        c->prev_win[i] = 0.0f;
    }

    c->band_ext = 0;
    c->q_unit_cnt = 0;
    for (int i = 0; i < 4; i++) {
        c->band_ext_data[i] = 0;
    }

    b->band_count = 0;
    b->q_unit_cnt_prev = 0;
    b->stereo_q_unit = 0;
    b->has_band_ext = 0;
    b->has_band_ext_data = 0;
    b->band_ext_q_unit = 0;
    b->grad_mode = 0;
    b->grad_boundary = 0;
    b->cpe_base_channel = 0;
    for (int i = 0; i < 30; i++) {
        b->is_signs[i] = 0;
    }
    b->reuseable = 0;
}