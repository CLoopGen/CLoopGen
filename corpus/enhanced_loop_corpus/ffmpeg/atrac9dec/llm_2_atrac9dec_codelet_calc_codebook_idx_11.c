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

extern ATRAC9ChannelData *c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // This changes sequential access to strided access and processes two iterations at once
    int i = 8;
    if (i % 2 == 0) {
        for (; i + 1 < c->q_unit_cnt; i += 2) {
            const int prev1 = c->scalefactors[i - 1];
            const int cur1 = c->scalefactors[i];
            const int next1 = c->scalefactors[i + 1];
            const int min1 = (prev1 > next1) ? next1 : prev1;

            const int prev2 = c->scalefactors[i];      // effectively [i+1-1]
            const int cur2 = c->scalefactors[i + 1];
            const int next2 = c->scalefactors[i + 2];
            const int min2 = (prev2 > next2) ? next2 : prev2;

            if ((cur1 - min1 >= 3 || 2 * cur1 - prev1 - next1 >= 3))
                c->codebookset[i] = 1;
            if ((cur2 - min2 >= 3 || 2 * cur2 - prev2 - next2 >= 3))
                c->codebookset[i + 1] = 1;
        }
    }
    for (; i < c->q_unit_cnt; i++) {
        const int prev = c->scalefactors[i - 1];
        const int cur = c->scalefactors[i];
        const int next = c->scalefactors[i + 1];
        const int min = (prev > next) ? next : prev;
        if ((cur - min >= 3 || 2 * cur - prev - next >= 3))
            c->codebookset[i] = 1;
    }
}
