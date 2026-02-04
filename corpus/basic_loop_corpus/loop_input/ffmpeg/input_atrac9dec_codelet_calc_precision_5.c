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
    b = (ATRAC9BlockData *)aligned_alloc(32, sizeof(ATRAC9BlockData));
    if (!b) exit(1);

    c = &b->channel[0];

    b->q_unit_cnt = 30;

    for (int i = 0; i < 2; i++) {
        ATRAC9ChannelData *ch = &b->channel[i];
        ch->band_ext = 0;
        ch->q_unit_cnt = 30;
        for (int j = 0; j < 4; j++)
            ch->band_ext_data[j] = 0;
        for (int j = 0; j < 31; j++) {
            ch->scalefactors[j] = 0;
            ch->scalefactors_prev[j] = 0;
        }
        for (int j = 0; j < 30; j++) {
            ch->precision_coarse[j] = rand() % 32;
            ch->precision_fine[j] = 0;
            ch->precision_mask[j] = 0;
            ch->codebookset[j] = 0;
        }
        for (int j = 0; j < 256; j++) {
            ch->q_coeffs_coarse[j] = 0;
            ch->q_coeffs_fine[j] = 0;
            ch->coeffs[j] = 0.0f;
        }
        for (int j = 0; j < 128; j++) {
            ch->prev_win[j] = 0.0f;
        }
    }

    b->band_count = 0;
    b->q_unit_cnt_prev = 0;
    b->stereo_q_unit = 0;
    b->has_band_ext = 0;
    b->has_band_ext_data = 0;
    b->band_ext_q_unit = 0;
    b->grad_mode = 0;
    b->grad_boundary = 0;
    for (int j = 0; j < 31; j++)
        b->gradient[j] = 0;
    b->cpe_base_channel = 0;
    for (int j = 0; j < 30; j++)
        b->is_signs[j] = 0;
    b->reuseable = 0;

    c = &b->channel[0];
}