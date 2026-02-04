#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *lpc;
extern float gamma;
extern int size;
extern int i;
extern float fac;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Processes elements at even indices first, then odd in a second pass
    int stride = 2;
    for (i = 0; i < stride; i++) {
        for (int j = i; j < size; j += stride) {
            out[j] = lpc[j] * fac;
            fac *= gamma;
        }
    }
}
