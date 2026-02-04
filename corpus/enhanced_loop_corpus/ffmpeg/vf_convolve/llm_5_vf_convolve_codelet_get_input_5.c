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
    for (y = n - ih; y < n; y++) {
        int offset = (n - ih - 1) * n;
        for (x = 0; x < n; x++) {
            FFTComplex temp = fft_hdata[offset + x];
            if (temp.re >= 0.0f) {
                fft_hdata[y * n + x].re = temp.re;
            } else {
                fft_hdata[y * n + x].re = 0.0f;
            }
            fft_hdata[y * n + x].im = 0;
        }
    }
}
