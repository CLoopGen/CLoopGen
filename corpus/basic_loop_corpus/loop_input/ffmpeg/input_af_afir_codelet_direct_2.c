#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

float *in;
FFTComplex *ir;
int len;
float *out;

void init_vars() {
    len = 8192;

    in = (float*)aligned_alloc(32, len * sizeof(float));
    ir = (FFTComplex*)aligned_alloc(32, len * sizeof(FFTComplex));
    out = (float*)aligned_alloc(32, len * sizeof(float));

    for (int i = 0; i < len; i++) {
        in[i] = (float)(i % 100) / 100.0f;
        ir[i].re = (float)((i + 10) % 90) / 100.0f;
        ir[i].im = 0.0f;
        out[i] = 0.0f;
    }
}