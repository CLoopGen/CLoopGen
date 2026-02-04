#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *dest;
extern int w;
extern int w2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step of 2, unrolling the loop by accessing two elements per iteration
    int start = w;
    int end = w + (w2 - w) / 2;
    int stride = 2;
    for (i = start; i < end - 1; i += stride) {
        dest[i]     = dest[2 * w - i - 1];
        dest[i + 1] = dest[2 * w - (i + 1) - 1];
    }
    // Handle remaining element if range is odd
    if (i == end - 1) {
        dest[i] = dest[2 * w - i - 1];
    }
}
