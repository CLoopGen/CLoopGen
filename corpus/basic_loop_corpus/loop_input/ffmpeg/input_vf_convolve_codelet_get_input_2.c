#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

FFTSample *fft_hdata_base_re;
FFTSample *fft_hdata_base_im;
FFTComplex *fft_hdata;
int n = 2048;
int ih = 512;
int y;
int x;

void init_vars() {
    size_t total_size = (size_t)n * n * sizeof(FFTComplex);
    fft_hdata = aligned_alloc(32, total_size);
    
    for (int i = 0; i < n * n; i++) {
        fft_hdata[i].re = (FFTSample)(i & 0xFF);
        fft_hdata[i].im = (FFTSample)((i >> 8) & 0xFF);
    }
}