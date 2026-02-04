#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

FFTComplex *fft_hdata;
int n = 1024;           // Determines data size: n x n matrix
int ih = 512;           // Must be <= n, used in loop bounds
int y;
int x;

void init_vars() {
    // Allocate n x n elements for fft_hdata
    fft_hdata = (FFTComplex*)calloc(n * n, sizeof(FFTComplex));
    if (!fft_hdata) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize existing elements to avoid undefined behavior when reading
    for (int i = 0; i < (n - ih) * n; i++) {
        fft_hdata[i].re = (FFTSample)(i & 0xFF);
        fft_hdata[i].im = (FFTSample)((i >> 8) & 0xFF);
    }
}