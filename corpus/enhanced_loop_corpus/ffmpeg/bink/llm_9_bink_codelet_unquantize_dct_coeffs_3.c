#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t block[64];
extern  uint32_t quant[64];
extern int coef_count;
extern int coef_idx[64];
extern  uint8_t *scan;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i < coef_count - 1; i += step) {
        int idx1 = coef_idx[i];
        int idx2 = coef_idx[i + 1];
        block[scan[idx1]] = (int)(block[scan[idx1]] * quant[idx1]) >> 11;
        block[scan[idx2]] = (int)(block[scan[idx2]] * quant[idx2]) >> 11;
    }
    // Handle odd leftover element
    if (i < coef_count) {
        int idx = coef_idx[i];
        block[scan[idx]] = (int)(block[scan[idx]] * quant[idx]) >> 11;
    }
}
