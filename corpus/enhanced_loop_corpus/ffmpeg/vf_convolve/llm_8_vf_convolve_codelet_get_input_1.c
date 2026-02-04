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
        for (x = 0; x < n; x += 2) {
            int idx1 = y * n + x;
            int idx2 = ih * n + x;
            fft_hdata[idx1].re = fft_hdata[idx2].re;
            fft_hdata[idx1].im = 0;
            if (x + 1 < n) {
                fft_hdata[idx1 + 1].re = fft_hdata[idx2 + 1].re;
                fft_hdata[idx1 + 1].im = 0;
            }
        }
    }
}
