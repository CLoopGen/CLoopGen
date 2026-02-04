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
    // Variant 1: Consecutive memory access using pointer arithmetic for better spatial locality
    FFTComplex *base = &fft_hdata[(n - ih) * n];
    FFTComplex *src_row = &fft_hdata[(n - ih - 1) * n];
    int rows = ih;
    int cols = n;
    for (int i = 0; i < rows; i++) {
        FFTComplex *dest = base + i * cols;
        for (int j = 0; j < cols; j++) {
            dest[j].re = src_row[j].re;
            dest[j].im = 0;
        }
    }
}
