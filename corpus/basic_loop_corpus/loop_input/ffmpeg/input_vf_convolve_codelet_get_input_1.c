#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

FFTSample *temp_data;
FFTComplex *fft_hdata;
int n = 1024;
int ih = 256;
int y;
int x;

void init_vars() {
    size_t total_size = (ih + 1) * (size_t)n;
    temp_data = (FFTSample*)calloc(total_size * 2, sizeof(FFTSample));
    if (!temp_data) {
        exit(1);
    }
    fft_hdata = (FFTComplex*)temp_data;
}

void cleanup() {
    free(temp_data);
}