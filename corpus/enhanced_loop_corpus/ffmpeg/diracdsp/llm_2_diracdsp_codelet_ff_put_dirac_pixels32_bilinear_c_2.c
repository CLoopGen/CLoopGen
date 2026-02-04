#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int x;
extern  uint8_t *s0;
extern  uint8_t *s1;
extern  uint8_t *s2;
extern  uint8_t *s3;
extern  uint8_t *w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    for (x = 0; x < 32; x += 2) {
        int idx1 = x;
        int idx2 = x + 1;
        dst[idx1] = ((s0[idx1] * w[0] + s1[idx1] * w[1] + s2[idx1] * w[2] + s3[idx1] * w[3] + 8) >> 4);
        if (idx2 < 32) {
            dst[idx2] = ((s0[idx2] * w[0] + s1[idx2] * w[1] + s2[idx2] * w[2] + s3[idx2] * w[3] + 8) >> 4);
        }
    }
}
