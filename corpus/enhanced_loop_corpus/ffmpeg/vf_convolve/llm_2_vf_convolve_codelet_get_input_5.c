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
    // Variant 1: Consecutive memory access using pointer arithmetic
    FFTComplex *base_src = &fft_hdata[(n - ih - 1) * n];
    FFTComplex *base_dst = &fft_hdata[(n - ih) * n];
    int rows = ih;
    int cols = n;

    for (int i = 0; i < rows; i++) {
        FFTComplex *dst_row = base_dst + i * cols;
        FFTComplex *src_row = base_src;
        for (int j = 0; j < cols; j++) {
            dst_row[j].re = src_row[j].re;
            dst_row[j].im = 0.0f;
        }
    }
}
