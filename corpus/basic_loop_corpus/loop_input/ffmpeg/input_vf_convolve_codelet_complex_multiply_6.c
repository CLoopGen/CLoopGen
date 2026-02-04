#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <time.h>

typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

FFTSample noise = 0.001f;
int n = 8192;
int start = 0;
int end = 32;
int y;
int x;

FFTComplex *input;
FFTComplex *filter;

void init_vars() {
    int total_size = n * end;
    input = (FFTComplex*)aligned_alloc(32, total_size * sizeof(FFTComplex));
    filter = (FFTComplex*)aligned_alloc(32, total_size * sizeof(FFTComplex));

    for (int i = 0; i < total_size; i++) {
        input[i].re = (float)rand() / RAND_MAX;
        input[i].im = (float)rand() / RAND_MAX;
        filter[i].re = (float)rand() / RAND_MAX;
        filter[i].im = (float)rand() / RAND_MAX;
    }

    noise = 0.001f;
    start = 0;
    end = 32;
    n = 8192;
}