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
    for (y = 0; y < ih; y++) {
        for (x = 0; x < n; x++) {
            int idx = y * n + x;
            int src_idx = ih * n + x;
            fft_hdata[idx].re = fft_hdata[src_idx].re;
            fft_hdata[idx].im = 0;
        }
    }
}
