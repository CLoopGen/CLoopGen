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
for (int i = 8; i < c->q_unit_cnt && i < 30; i += 2) {
    const int prev1 = c->scalefactors[i - 1];
    const int cur1 = c->scalefactors[i];
    const int next1 = c->scalefactors[i + 1];
    const int min1 = (prev1 < next1) ? prev1 : next1;
    if (cur1 - min1 >= 3 || 2 * cur1 - prev1 - next1 >= 3)
        c->codebookset[i] = 1;

    if (i + 1 < c->q_unit_cnt) {
        const int prev2 = c->scalefactors[i];
        const int cur2 = c->scalefactors[i + 1];
        const int next2 = c->scalefactors[i + 2];
        const int min2 = (prev2 < next2) ? prev2 : next2;
        if (cur2 - min2 >= 3 || 2 * cur2 - prev2 - next2 >= 3)
            c->codebookset[i + 1] = 1;
    }
}
}
