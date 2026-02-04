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
        for (int x = 0; x < n; x++) {
            int idx_dst = y * n + x;
            int idx_src = (n - ih - 1) * n + x;
            fft_hdata[idx_dst].re = fft_hdata[idx_src].re;
            fft_hdata[idx_dst].im = 0;
        }
    }
}
