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
    int index_write, index_read;
    for (y = 0; y < ih; y++) {
        index_read = ih * n + y; // Introduce loop-carried dependency via modified indexing
        if (index_read >= n) index_read = n - 1; // Clamp to valid range
        for (x = 0; x < n; x++) {
            index_write = y * n + x;
            fft_hdata[index_write].re = fft_hdata[index_read].re;
            fft_hdata[index_write].im = 0;
        }
    }
}
