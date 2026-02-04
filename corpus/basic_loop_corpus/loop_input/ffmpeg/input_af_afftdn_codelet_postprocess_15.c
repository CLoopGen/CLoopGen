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

FFTComplex *in;
int len = 1 << 20; // Approximately 4MB of data (1M complex floats)
double d1;
double d2;
double d3;
double d4;
double d6;
double d7;
double d8;
double d9;
double d10;
int n;
int i;
int k;

void init_vars() {
    in = (FFTComplex*)aligned_alloc(32, len * sizeof(FFTComplex));
    if (!in) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < len; idx++) {
        in[idx].re = (float)(drand48() * 2.0 - 1.0);
        in[idx].im = (float)(drand48() * 2.0 - 1.0);
    }

    d1 = 0.1;
    d2 = 0.2;
    d3 = 0.3;
    d4 = 0.4;
    d6 = 0.5;
    d7 = 0.01;
    d8 = 0.02;
    d9 = 0.6;
    d10 = 0.7;

    n = len;
}