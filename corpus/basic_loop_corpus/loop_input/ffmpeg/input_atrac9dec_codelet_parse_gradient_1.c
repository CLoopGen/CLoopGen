#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

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
int sign;
int base;
uint8_t *curve;
float scale;

void init_vars() {
    b = (ATRAC9BlockData*)aligned_alloc(32, sizeof(ATRAC9BlockData));
    memset(b, 0, sizeof(ATRAC9BlockData));

    grad_range[0] = 0;
    grad_range[1] = 31;

    sign = 1;
    base = 100;
    scale = 2.5f;

    size_t curve_size = 31;
    curve = (uint8_t*)malloc(curve_size);
    for (size_t i = 0; i < curve_size; i++) {
        curve[i] = (uint8_t)(i * 3);
    }
}