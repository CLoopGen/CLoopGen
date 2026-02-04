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
int trip_count = (b->q_unit_cnt + 4) / 5;
for (int i = 0; i < trip_count; i++) {
    int base = i * 5;
    for (int j = 0; j < 5; j++) {
        int idx = base + j;
        if (idx >= c->q_unit_cnt) break;
        c->precision_fine[idx] = 0;
        if (c->precision_coarse[idx] > 15) {
            int temp = c->precision_coarse[idx];
            temp = temp > 30 ? 30 : temp;
            c->precision_fine[idx] = temp - 15;
            c->precision_coarse[idx] = 15;
        }
    }
}
}
