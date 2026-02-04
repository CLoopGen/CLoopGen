#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int b_w;
extern int b_h;
extern int x;
extern int y;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int stride1;
extern int stride2;
extern int a;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Loop Unrolling (factor of 2)
    // This variant assumes b_w is even for simplicity and accesses memory in pairs to promote consecutive access patterns.
    for (y = 0; y < b_h; y++) {
        for (x = 0; x < b_w - 1; x += 2) {
            dst[x]     = (a * src1[x]     + b * src2[x]     + 4) >> 3;
            dst[x + 1] = (a * src1[x + 1] + b * src2[x + 1] + 4) >> 3;
        }
        if (x < b_w) {
            dst[x] = (a * src1[x] + b * src2[x] + 4) >> 3;
        }
        src1 += stride1;
        src2 += stride2;
        dst += stride;
    }
}
