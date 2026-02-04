#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern int k;
extern int32_t lpc32[16];
extern int16_t lpc[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Processes elements in a non-consecutive manner: k and k+1 with step 2
    int i;
    for (i = 0; i < order; i += 2) {
        if (i < order) {
            lpc[i] = (lpc32[i] + 16) >> 5;
        }
        if (i + 1 < order) {
            lpc[i + 1] = (lpc32[i + 1] + 16) >> 5;
        }
    }
}
