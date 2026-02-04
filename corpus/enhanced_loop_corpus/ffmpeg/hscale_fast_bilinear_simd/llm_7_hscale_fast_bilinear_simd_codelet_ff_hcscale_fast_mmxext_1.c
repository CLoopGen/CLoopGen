#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst1;
extern int16_t *dst2;
extern int dstWidth;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int srcW;
extern int xInc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_i = dstWidth;
    for (i = dstWidth - 1; (i * xInc) >> 16 >= srcW - 1; i--) {
        // Introduce loop-carried dependency: current computation depends on previous i value
        if (prev_i != dstWidth) {
            dst1[prev_i] += src1[srcW - 1] * 64; // Read after write: WAR-like pattern with prior iteration
        }
        dst1[i] = src1[srcW - 1] * 128;
        dst2[i] = src2[srcW - 1] * 128;
        prev_i = i; // Create loop-carried dependency via prev_i
        // Added RAW and WAW dependencies across iterations
    }
}
