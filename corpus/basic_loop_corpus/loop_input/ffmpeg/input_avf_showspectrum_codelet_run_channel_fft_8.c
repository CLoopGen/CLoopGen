#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

float a;
float b;
float S;
float c;
FFTComplex *g;
FFTComplex *h;
int L;

void init_vars() {
    L = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime

    g = (FFTComplex*)aligned_alloc(32, L * sizeof(FFTComplex));
    h = (FFTComplex*)aligned_alloc(32, L * sizeof(FFTComplex));

    for (int i = 0; i < L; i++) {
        g[i].re = (float)(i % 100) * 0.1f;
        g[i].im = (float)((i + 10) % 100) * 0.1f;
        h[i].re = (float)(i % 80) * 0.1f;
        h[i].im = (float)((i + 5) % 80) * 0.1f;
    }

    a = 0.0f;
    b = 0.0f;
    S = 0.0f;
    c = 0.0f;
}