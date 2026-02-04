#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int w;
extern int h;
extern int color;
extern int stride;
extern int i;
extern int j;
extern uint32_t *dst2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled loop (factor of 4)
    for (j = 0; j < h; j++) {
        dst2 = (uint32_t *)dst;
        i = 0;
        // Unroll by 4 for consecutive accesses
        for (; i <= w - 4; i += 4) {
            dst2[i]     = color;
            dst2[i + 1] = color;
            dst2[i + 2] = color;
            dst2[i + 3] = color;
        }
        // Handle remainder
        for (; i < w; i++) {
            dst2[i] = color;
        }
        dst += stride;
    }
}
