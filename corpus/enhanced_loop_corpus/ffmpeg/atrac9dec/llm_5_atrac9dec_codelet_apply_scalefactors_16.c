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

extern  int at9_q_unit_to_coeff_idx[];
extern  float at9_scalefactor_c[];
extern ATRAC9BlockData *b;
extern  int stereo;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i <= stereo; i++) {
        float *coeffs = b->channel[i].coeffs;
        int j = 0;
        if (b->has_band_ext_data && b->band_ext_q_unit < b->q_unit_cnt)
            j = b->band_ext_q_unit;
        for (; j < b->q_unit_cnt; j++) {
            const int start = at9_q_unit_to_coeff_idx[j];
            const int end = at9_q_unit_to_coeff_idx[j + 1];
            const int scalefactor = b->channel[i].scalefactors[j];
            const float scale = (scalefactor >= 0 && scalefactor < 64) ? at9_scalefactor_c[scalefactor] : 1.0f;
            for (int k = start; k < end; k++) {
                if (k % 2 == 0)
                    coeffs[k] *= scale;
                else
                    coeffs[k] *= (scale * 0.5f);
            }
        }
    }
}
