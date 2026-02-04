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

ATRAC9ChannelData *c;
int *baseline;
int base;
int unit_cnt;

void init_vars() {
    unit_cnt = 31;
    base = 1000;

    c = (ATRAC9ChannelData*)aligned_alloc(32, sizeof(ATRAC9ChannelData));
    baseline = (int*)malloc(unit_cnt * sizeof(int));

    for (int i = 0; i < unit_cnt; i++) {
        c->scalefactors[i] = i * 2;
        baseline[i] = i * 3;
    }

    c->q_unit_cnt = unit_cnt;
    for (int i = 0; i < 4; i++)
        c->band_ext_data[i] = 0;
    for (int i = 0; i < 31; i++)
        c->scalefactors_prev[i] = 0;
    for (int i = 0; i < 30; i++) {
        c->precision_coarse[i] = 0;
        c->precision_fine[i] = 0;
        c->precision_mask[i] = 1;
        c->codebookset[i] = 0;
    }
    for (int i = 0; i < 256; i++) {
        c->q_coeffs_coarse[i] = 0;
        c->q_coeffs_fine[i] = 0;
        c->coeffs[i] = 0.0f;
    }
    for (int i = 0; i < 128; i++)
        c->prev_win[i] = 0.0f;
}