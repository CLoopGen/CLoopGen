#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

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

int at9_q_unit_to_coeff_idx[32];
ATRAC9ChannelData *c;
float sf[6];
int s_unit;
int e_unit;

void init_vars() {
    c = (ATRAC9ChannelData*)aligned_alloc(32, sizeof(ATRAC9ChannelData));
    if (!c) exit(1);

    for (int i = 0; i < 256; i++) {
        c->coeffs[i] = 1.0f + 0.01f * i;
    }
    for (int i = 0; i < 128; i++) {
        c->prev_win[i] = 0.5f;
    }

    for (int i = 0; i < 31; i++) {
        c->scalefactors[i] = i * 2;
        if (i < 30) {
            c->precision_coarse[i] = 4;
            c->precision_fine[i] = 2;
            c->precision_mask[i] = 1;
            c->codebookset[i] = 3;
        }
    }
    memcpy(c->scalefactors_prev, c->scalefactors, sizeof(c->scalefactors_prev));
    for (int i = 0; i < 256; i++) {
        c->q_coeffs_coarse[i] = i % 17;
        c->q_coeffs_fine[i] = i % 13;
    }

    c->band_ext = 1;
    c->q_unit_cnt = 30;
    for (int i = 0; i < 4; i++) {
        c->band_ext_data[i] = 0;
    }

    const int num_units = 30;
    s_unit = 0;
    e_unit = num_units > 30 ? 30 : num_units;

    for (int i = 0; i <= e_unit; i++) {
        at9_q_unit_to_coeff_idx[i] = (int)(256.0 * pow(i / (double)e_unit, 2));
    }

    for (int i = 0; i < 6; i++) {
        sf[i] = 0.8f + 0.05f * i;
    }
}