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

uint8_t at9_q_unit_to_coeff_cnt[32];
ATRAC9ChannelData *c;
int avg;

void init_vars() {
    c = (ATRAC9ChannelData*)aligned_alloc(32, sizeof(ATRAC9ChannelData));
    
    c->q_unit_cnt = 30;
    c->band_ext = 0;
    for (int i = 0; i < 4; i++) {
        c->band_ext_data[i] = 0;
    }
    for (int i = 0; i < 31; i++) {
        c->scalefactors[i] = (i % 7) * 3;
        c->scalefactors_prev[i] = (i % 5) * 4;
    }
    for (int i = 0; i < 30; i++) {
        c->precision_coarse[i] = (i % 3) + 1;
        c->precision_fine[i] = (i % 4) + 1;
        c->precision_mask[i] = 1;
        c->codebookset[i] = 0;
    }
    for (int i = 0; i < 256; i++) {
        c->q_coeffs_coarse[i] = (i % 17) * 5;
        c->q_coeffs_fine[i] = (i % 19) * 3;
        c->coeffs[i] = (float)((i % 23) * 2);
        if (i < 128) {
            c->prev_win[i] = (float)((i % 11) * 7);
        }
    }
    for (int i = 0; i < 32; i++) {
        at9_q_unit_to_coeff_cnt[i] = (i % 3 == 0) ? 16 : 8;
    }
    avg = 10;
}