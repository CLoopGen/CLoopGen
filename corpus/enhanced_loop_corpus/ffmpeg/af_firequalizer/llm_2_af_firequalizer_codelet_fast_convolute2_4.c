#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern float *restrict data0;
extern float *restrict data1;
extern int nsamples;
extern FFTComplex *buf;
extern int center;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    int stride = 2;
    int half_samples = nsamples / stride;
    for (k = 0; k < half_samples; k++) {
        int idx = k * stride;
        buf[center + idx].re = data0[idx];
        buf[center + idx].im = data1[idx];
    }
    // Handle remaining element if nsamples is odd
    if (nsamples % 2 == 1) {
        int last_idx = nsamples - 1;
        buf[center + last_idx].re = data0[last_idx];
        buf[center + last_idx].im = data1[last_idx];
    }
}
