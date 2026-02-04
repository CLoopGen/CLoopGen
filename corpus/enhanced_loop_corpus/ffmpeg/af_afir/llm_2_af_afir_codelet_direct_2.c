#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern  float *in;
extern  FFTComplex *ir;
extern int len;
extern float *out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of accessing in[n-m] with decreasing stride, we precompute a strided view
    // by reversing the effective access order with fixed increments.
    int stride = 1;
    for (int n = 0; n < len; n += stride) {
        float sum = out[n];
        for (int m = 0; m <= n; m++) {
            sum += ir[m].re * in[n - m];
        }
        out[n] = sum;
    }
}
