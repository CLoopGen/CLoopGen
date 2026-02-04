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
int k;

void init_vars() {
    nsamples = 65536 * 4;  // Approximately 1MB of FFTComplex data (65536*4 ~ 262144 elements -> ~1.05MB per array)

    buf = (FFTComplex*)aligned_alloc(32, nsamples * sizeof(FFTComplex));
    data0 = (float*)aligned_alloc(32, nsamples * sizeof(float));
    data1 = (float*)aligned_alloc(32, nsamples * sizeof(float));

    for (int i = 0; i < nsamples; i++) {
        buf[i].re = (FFTSample)(i % 100) + 0.5f;
        buf[i].im = (FFTSample)((i + 10) % 100) - 0.3f;
    }

    k = 0;
}