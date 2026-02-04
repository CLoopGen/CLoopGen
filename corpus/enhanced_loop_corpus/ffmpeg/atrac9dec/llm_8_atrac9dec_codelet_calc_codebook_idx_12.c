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
    for (int i = 10; i < c->q_unit_cnt && i < 30; i += 2) {
        const int cur = c->scalefactors[i];
        const int cnd = at9_q_unit_to_coeff_cnt[i] == 16;
        const int prev = c->scalefactors[i - 1];
        const int next = (i + 1 < c->q_unit_cnt) ? c->scalefactors[i + 1] : prev;
        const int min = (prev < next) ? prev : next;
        if (c->codebookset[i])
            continue;
        const int diff = cur - min;
        const int threshold = avg - cnd;
        c->codebookset[i] = (diff >= 2) && (cur >= threshold);
    }
}
