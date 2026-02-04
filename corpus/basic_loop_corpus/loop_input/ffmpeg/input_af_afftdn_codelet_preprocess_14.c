#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <math.h>

typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

FFTSample *in_data;
FFTComplex *in;
int len;
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
    const int data_size_mb = 64;
    const int total_elements = (data_size_mb * 1024 * 1024) / sizeof(FFTComplex);
    
    in_data = (FFTSample*)aligned_alloc(32, total_elements * sizeof(FFTComplex));
    in = (FFTComplex*)in_data;

    for (int idx = 0; idx < total_elements; idx++) {
        in[idx].re = (float)(drand48() * 2.0 - 1.0);
        in[idx].im = (float)(drand48() * 2.0 - 1.0);
    }

    len = total_elements;
    n = len;

    d7 = 0.01;
    d8 = 0.02;
    d9 = 0.5;
    d10 = d9;

    d1 = 0.0;
    d2 = 0.0;
    d3 = 0.0;
    d4 = 0.0;
    d6 = 0.3;
}