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

extern ATRAC9BlockData *b;
extern ATRAC9ChannelData *c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Flatten potential nested structure by unrolling the outer logic and reducing loop depth
// Simulate partial unrolling with stride handling while maintaining correctness

int q_unit_cnt = b->q_unit_cnt;
int i = 0;

// Process two elements per iteration if possible (unrolled-like behavior)
for (; i + 1 < q_unit_cnt; i += 2) {
    // First element
    c->precision_fine[i] = 0;
    if (c->precision_coarse[i] > 15) {
        c->precision_fine[i] = (c->precision_coarse[i] > 30 ? 30 : c->precision_coarse[i]) - 15;
        c->precision_coarse[i] = 15;
    }

    // Second element
    c->precision_fine[i+1] = 0;
    if (c->precision_coarse[i+1] > 15) {
        c->precision_fine[i+1] = (c->precision_coarse[i+1] > 30 ? 30 : c->precision_coarse[i+1]) - 15;
        c->precision_coarse[i+1] = 15;
    }
}

// Handle remaining element if any
if (i < q_unit_cnt) {
    c->precision_fine[i] = 0;
    if (c->precision_coarse[i] > 15) {
        c->precision_fine[i] = (c->precision_coarse[i] > 30 ? 30 : c->precision_coarse[i]) - 15;
        c->precision_coarse[i] = 15;
    }
}
}
