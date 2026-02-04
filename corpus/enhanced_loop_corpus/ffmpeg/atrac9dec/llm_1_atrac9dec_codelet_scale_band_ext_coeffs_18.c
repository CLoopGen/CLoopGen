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
    // Flattened single loop with manual index tracking
    int flat_index = at9_q_unit_to_coeff_idx[s_unit];
    int unit_idx = s_unit;
    int sf_idx = 0;
    const int total_end = at9_q_unit_to_coeff_idx[e_unit];

    for (int j = flat_index; j < total_end; j++) {
        // Check if we need to advance to the next unit
        if (j >= at9_q_unit_to_coeff_idx[unit_idx + 1]) {
            unit_idx++;
            sf_idx++;
        }
        c->coeffs[j] *= sf[sf_idx];
    }
}
