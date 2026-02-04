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
    int total = ih * n;
    for (int i = 0; i < total; i++) {
        y = i / n;
        x = i % n;
        fft_hdata[y * n + x].re = fft_hdata[ih * n + x].re;
        fft_hdata[y * n + x].im = 0;
    }
}
