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
    const int range = e_unit - s_unit;
    for (int i = 0; i < range; i++) {
        const int start = at9_q_unit_to_coeff_idx[s_unit + i];
        const int end = at9_q_unit_to_coeff_idx[s_unit + i + 1];
        int j = start;
        for (; j < end; j += 4) {
            c->coeffs[j] *= sf[i];
            c->coeffs[j+1] *= sf[i];
            c->coeffs[j+2] *= sf[i];
            c->coeffs[j+3] *= sf[i];
        }
        // Handle remaining elements
        for (; j < end; j++) {
            c->coeffs[j] *= sf[i];
        }
    }
}
