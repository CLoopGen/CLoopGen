#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern  float *src0;
extern  float *src1;
extern  float *win;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset indexing
    // Instead of accessing src0[i], src1[j], etc., we reindex to traverse arrays consecutively from start
    // We rewrite the loop to iterate k from 0 to len-1, mapping i = -len + k, j = len - 1 - k
    for (int k = 0; k < len; k++) {
        int idx_i = -len + k;
        int idx_j = len - 1 - k;
        float s0 = src0[idx_i];
        float s1 = src1[idx_j];
        float wi = win[idx_i];
        float wj = win[idx_j];
        dst[idx_i] = s0 * wj - s1 * wi;
        dst[idx_j] = s0 * wi + s1 * wj;
    }
}
