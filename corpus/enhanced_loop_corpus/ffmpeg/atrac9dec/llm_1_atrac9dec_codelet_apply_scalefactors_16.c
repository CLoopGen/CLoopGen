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
        const int q_unit_cnt = b->q_unit_cnt;
        int flat_index = 0;
        for (int j = 0; j < q_unit_cnt; j++) {
            const int start = at9_q_unit_to_coeff_idx[j + 0];
            const int end = at9_q_unit_to_coeff_idx[j + 1];
            const int scalefactor = b->channel[i].scalefactors[j];
            const float scale = at9_scalefactor_c[scalefactor];
            for (int k = start; k < end; k++, flat_index++) {
                if (flat_index >= 256) break;
                coeffs[k] *= scale;
            }
        }
    }
}
