#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int srcWidth;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride (simulating potential SIMD-like alignment or padding)
    // Assume effective width reduced by half to maintain bounds safety under stride
    int effective_width = (srcWidth - 1) / 2;
    for (x = 0; x < effective_width; x++) {
        int idx = 2 * x; // Stride of 2 in input sampling
        dst[4 * x + 1] = (3 * src[idx] + src[idx + 1]) >> 2;
        dst[4 * x + 2] = (src[idx] + 3 * src[idx + 1]) >> 2;
    }
}
