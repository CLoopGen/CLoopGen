#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

FFTSample *fft_hdata_re_ptr;
FFTSample *fft_hdata_im_ptr;
FFTComplex *fft_hdata;
int n;
int ih;
int y;
int x;

void init_vars() {
    n = 8192;
    ih = 32;

    size_t total_size = (ih + 1) * n;
    fft_hdata = (FFTComplex*)calloc(total_size, sizeof(FFTComplex));
    if (!fft_hdata) {
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        fft_hdata[i].re = (FFTSample)(i & 0xFF);
        fft_hdata[i].im = 0.0f;
    }
}