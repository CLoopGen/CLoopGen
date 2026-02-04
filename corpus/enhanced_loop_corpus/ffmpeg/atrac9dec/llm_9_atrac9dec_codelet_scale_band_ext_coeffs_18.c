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

extern  int at9_q_unit_to_coeff_idx[];
extern ATRAC9ChannelData *c;
extern float sf[6];
extern  int s_unit;
extern  int e_unit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int stride = 2;
    for (int i = s_unit; i < e_unit; i += stride) {
        float scale1 = sf[i - s_unit];
        float scale2 = (i + 1 < e_unit) ? sf[i + 1 - s_unit] : 1.0f;
        const int start1 = at9_q_unit_to_coeff_idx[i + 0];
        const int end1 = at9_q_unit_to_coeff_idx[i + 1];
        for (int j = start1; j < end1; j++)
            c->coeffs[j] *= scale1;
        if (i + 1 < e_unit) {
            const int start2 = at9_q_unit_to_coeff_idx[i + 1];
            const int end2 = at9_q_unit_to_coeff_idx[i + 2];
            for (int j = start2; j < end2; j++)
                c->coeffs[j] *= scale2;
        }
    }
}
