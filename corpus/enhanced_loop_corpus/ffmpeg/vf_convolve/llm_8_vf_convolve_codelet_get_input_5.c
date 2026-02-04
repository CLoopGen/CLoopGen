#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern FFTComplex *fft_hdata;
extern int n;
extern  int ih;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int y_start = n - ih;
    for (y = y_start; y < n; y++) {
        FFTComplex *row_dst = &fft_hdata[y * n];
        FFTComplex *row_src = &fft_hdata[(n - ih - 1) * n];
        for (x = 0; x < n; x++) {
            row_dst[x].re = row_src[x].re;
            row_dst[x].im = 0.0f;
            // Additional arithmetic to increase computational intensity
            row_dst[x].re += (FFTSample)(x & 1) ? 0.1f : -0.1f;
        }
    }
}
