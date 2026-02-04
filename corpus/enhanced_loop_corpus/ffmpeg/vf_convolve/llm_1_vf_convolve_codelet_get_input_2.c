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
    for (int idx = (n - ih) * n; idx < n * n; idx++) {
        fft_hdata[idx].re = fft_hdata[(n - ih - 1) * n + (idx % n)].re;
        fft_hdata[idx].im = 0;
    }
}
