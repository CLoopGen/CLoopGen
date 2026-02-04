#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

float *restrict data0;
float *restrict data1;
int nsamples;
FFTComplex *buf;
int center;
int k;

void init_vars() {
    nsamples = 1 << 20;  // 1 million samples, roughly 8MB of output data (2 floats per complex)
    
    data0 = (float*)aligned_alloc(32, nsamples * sizeof(float));
    data1 = (float*)aligned_alloc(32, nsamples * sizeof(float));
    buf = (FFTComplex*)aligned_alloc(32, 2 * nsamples * sizeof(FFTComplex));  // buffer larger than used
    
    center = nsamples;  // place input in the middle to avoid overlap issues
    
    for (int i = 0; i < nsamples; i++) {
        data0[i] = (float)(i + 1);
        data1[i] = (float)(-(i + 1));
    }
}