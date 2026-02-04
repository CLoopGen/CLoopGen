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
    // Variant 1: Consecutive memory access with pointer arithmetic
    FFTComplex *base = fft_hdata;
    for (y = 0; y < ih; y++) {
        FFTComplex *dest_row = base + y * n;
        FFTComplex *src_row = base + ih * n;
        for (x = 0; x < n; x++) {
            dest_row[x].re = src_row[x].re;
            dest_row[x].im = 0;
        }
    }
}
