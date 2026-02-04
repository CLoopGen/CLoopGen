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

int at9_q_unit_to_coeff_idx[32];
ATRAC9BlockData *b;
float *src;
float *dst;

void init_vars() {
    b = (ATRAC9BlockData*)aligned_alloc(32, sizeof(ATRAC9BlockData));
    const int total_data_size = 16777216; // ~16MB to target ~0.01s runtime
    src = (float*)aligned_alloc(32, total_data_size * sizeof(float));
    dst = (float*)aligned_alloc(32, total_data_size * sizeof(float));

    for (int i = 0; i < total_data_size; i++) {
        src[i] = (float)(i % 1000) / 100.0f;
        dst[i] = 0.0f;
    }

    b->q_unit_cnt = 20;
    b->stereo_q_unit = 5;
    b->has_band_ext = 0;
    b->has_band_ext_data = 0;
    b->grad_mode = 0;
    b->grad_boundary = 0;
    b->cpe_base_channel = 0;
    b->reuseable = 1;

    for (int i = 0; i < 31; i++) {
        b->gradient[i] = 0;
    }

    for (int i = 0; i < 30; i++) {
        b->is_signs[i] = (i % 2 == 0) ? 1 : -1;
    }

    int base_index = 0;
    for (int i = 0; i <= b->q_unit_cnt; i++) {
        at9_q_unit_to_coeff_idx[i] = base_index;
        if (i >= b->stereo_q_unit) {
            base_index += 10000;
        } else {
            base_index += 5000;
        }
        if (base_index > total_data_size - 10000) {
            base_index = total_data_size - (b->q_unit_cnt - i) * 1000;
            break;
        }
    }
    at9_q_unit_to_coeff_idx[b->q_unit_cnt] = total_data_size;
}