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

extern  uint8_t at9_q_unit_to_coeff_cnt[];
extern ATRAC9ChannelData *c;
extern int avg;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop by processing two iterations at once
    // This changes access pattern to non-consecutive, strided traversal of scalefactors and codebookset arrays
    for (int i = 12; i < c->q_unit_cnt - 1; i += 2) {
        const int cur1 = c->scalefactors[i];
        const int cur2 = c->scalefactors[i + 1];
        const int cnd1 = at9_q_unit_to_coeff_cnt[i] == 16;
        const int cnd2 = at9_q_unit_to_coeff_cnt[i + 1] == 16;
        const int min1 = (c->scalefactors[i + 1] > c->scalefactors[i - 1]) ? c->scalefactors[i - 1] : c->scalefactors[i + 1];
        const int min2 = (c->scalefactors[i + 2] > c->scalefactors[i]) ? c->scalefactors[i] : c->scalefactors[i + 2];

        if (!c->codebookset[i] && ((cur1 - min1) >= 2) && (cur1 >= (avg - cnd1)))
            c->codebookset[i] = 1;

        if (!c->codebookset[i + 1] && ((cur2 - min2) >= 2) && (cur2 >= (avg - cnd2)))
            c->codebookset[i + 1] = 1;
    }
    // Handle remaining element if q_unit_cnt is odd
    if ((c->q_unit_cnt % 2) && (c->q_unit_cnt - 1) >= 12) {
        const int i = c->q_unit_cnt - 1;
        const int cur = c->scalefactors[i];
        const int cnd = at9_q_unit_to_coeff_cnt[i] == 16;
        const int min = (c->scalefactors[i + 1] > c->scalefactors[i - 1]) ? c->scalefactors[i - 1] : c->scalefactors[i + 1];
        if (!c->codebookset[i])
            c->codebookset[i] = (((cur - min) >= 2) && (cur >= (avg - cnd)));
    }
}
