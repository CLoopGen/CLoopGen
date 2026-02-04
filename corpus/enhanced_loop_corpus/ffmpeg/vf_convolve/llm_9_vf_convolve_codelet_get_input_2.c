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
    int total_elements = ih * n;
    int idx;
    FFTComplex *dst = &fft_hdata[(n - ih) * n];
    const FFTComplex *src = &fft_hdata[(n - ih - 1) * n];
    for (idx = 0; idx < total_elements; idx++) {
        dst[idx].re = src[idx % n].re;
        dst[idx].im = 0.0f;
    }
}
