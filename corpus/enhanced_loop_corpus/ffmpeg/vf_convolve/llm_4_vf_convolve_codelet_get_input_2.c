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
        if (y >= 0) {
            for (x = 0; x < n; x++) {
                fft_hdata[y * n + x].re = fft_hdata[(n - ih - 1) * n + x].re;
                fft_hdata[y * n + x].im = 0;
            }
        }
    }
}
