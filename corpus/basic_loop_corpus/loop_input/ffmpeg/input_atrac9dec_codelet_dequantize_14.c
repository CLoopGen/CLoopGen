#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <malloc.h>

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

float at9_quant_step_coarse[32];
float at9_quant_step_fine[32];
int at9_q_unit_to_coeff_idx[31];
ATRAC9ChannelData *c;

void init_vars() {
    c = (ATRAC9ChannelData*)aligned_alloc(32, sizeof(ATRAC9ChannelData));
    if (!c) exit(1);

    memset(c, 0, sizeof(ATRAC9ChannelData));

    for (int i = 0; i < 32; i++) {
        at9_quant_step_coarse[i] = 0.5f + i * 0.1f;
        at9_quant_step_fine[i] = 0.1f + i * 0.05f;
    }

    c->q_unit_cnt = 30;
    for (int i = 0; i <= c->q_unit_cnt; i++) {
        at9_q_unit_to_coeff_idx[i] = i * 8;
    }

    for (int i = 0; i < 30; i++) {
        c->precision_coarse[i] = (i * 7) % 32;
        c->precision_fine[i] = (i * 5) % 32;
    }

    for (int i = 0; i < 256; i++) {
        c->q_coeffs_coarse[i] = (i * 13) % 100 - 50;
        c->q_coeffs_fine[i] = (i * 17) % 50 - 25;
    }
}