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

void init_vars() {
    c = (ATRAC9ChannelData*)aligned_alloc(32, sizeof(ATRAC9ChannelData));
    
    c->band_ext = 0;
    c->q_unit_cnt = 30;  // Set to ensure i+1 <= 30 (scalefactors has size 31)
    
    for (int i = 0; i < 4; i++)
        c->band_ext_data[i] = 0;
    
    for (int i = 0; i < 31; i++) {
        c->scalefactors[i] = (i == 0) ? 10 : ((i % 2) ? 8 : 12);
        c->scalefactors_prev[i] = 0;
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
}