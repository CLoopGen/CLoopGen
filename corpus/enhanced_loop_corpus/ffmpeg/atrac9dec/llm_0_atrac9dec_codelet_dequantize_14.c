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
extern  float at9_quant_step_coarse[];
extern  float at9_quant_step_fine[];
extern ATRAC9ChannelData *c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int q_unit_cnt = c->q_unit_cnt;
    for (int i = 0; i < q_unit_cnt; i++) {
        const int start = at9_q_unit_to_coeff_idx[i + 0];
        const int end = at9_q_unit_to_coeff_idx[i + 1];
        const float coarse_c = at9_quant_step_coarse[c->precision_coarse[i]];
        const float fine_c = at9_quant_step_fine[c->precision_fine[i]];
        int j = start;
        for (; j < end - 3; j += 4) {
            const float vc0 = c->q_coeffs_coarse[j + 0] * coarse_c;
            const float vf0 = c->q_coeffs_fine[j + 0] * fine_c;
            const float vc1 = c->q_coeffs_coarse[j + 1] * coarse_c;
            const float vf1 = c->q_coeffs_fine[j + 1] * fine_c;
            const float vc2 = c->q_coeffs_coarse[j + 2] * coarse_c;
            const float vf2 = c->q_coeffs_fine[j + 2] * fine_c;
            const float vc3 = c->q_coeffs_coarse[j + 3] * coarse_c;
            const float vf3 = c->q_coeffs_fine[j + 3] * fine_c;
            c->coeffs[j + 0] = vc0 + vf0;
            c->coeffs[j + 1] = vc1 + vf1;
            c->coeffs[j + 2] = vc2 + vf2;
            c->coeffs[j + 3] = vc3 + vf3;
        }
        for (; j < end; j++) {
            const float vc = c->q_coeffs_coarse[j] * coarse_c;
            const float vf = c->q_coeffs_fine[j] * fine_c;
            c->coeffs[j] = vc + vf;
        }
    }
}
