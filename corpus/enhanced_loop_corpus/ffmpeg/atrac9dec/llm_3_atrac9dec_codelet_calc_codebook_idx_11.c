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
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    // We create a static index map that accesses elements in reverse order within the valid range
    int indices[256];
    int count = 0;
    for (int j = 8; j < c->q_unit_cnt; j++) {
        indices[count++] = j;
    }
    // Reverse the access order (indirect traversal)
    for (int k = 0; k < count; k++) {
        int i = indices[count - 1 - k];  // reverse access
        const int prev = c->scalefactors[i - 1];
        const int cur = c->scalefactors[i];
        const int next = c->scalefactors[i + 1];
        const int min = (prev > next) ? next : prev;
        if ((cur - min >= 3 || 2 * cur - prev - next >= 3))
            c->codebookset[i] = 1;
    }
}
