#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    for (i = 0; i < 64; i += 2) {
        dst[i]     = src[i];
        if (i + 1 < 64) {
            dst[i + 1] = src[i + 1];
        }
    }
}
