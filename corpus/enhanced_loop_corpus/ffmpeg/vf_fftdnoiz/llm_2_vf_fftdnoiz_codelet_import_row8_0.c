#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern FFTComplex *dst;
extern uint8_t *src;
extern int rw;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    int stride = 2;
    int limit = rw - (rw % stride); // Ensure we don't go out of bounds
    for (j = 0; j < limit; j += stride) {
        dst[j].re = src[j];
        dst[j].im = 0;
    }
    // Handle remaining element if rw is odd
    if (rw % stride && j < rw) {
        dst[j].re = src[j];
        dst[j].im = 0;
    }
}
