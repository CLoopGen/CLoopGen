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
extern int start;
extern int count;
extern float maxval;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < count; i += 2) {
        c->coeffs[start + i] /= maxval;
        if (i + 1 < count)
            c->coeffs[start + i + 1] /= maxval;
    }
}
