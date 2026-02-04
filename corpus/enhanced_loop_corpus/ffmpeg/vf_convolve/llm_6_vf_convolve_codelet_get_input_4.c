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
    FFTSample *re_data = (FFTSample*)fft_hdata;
    int base_idx, src_idx;
    for (y = 0; y < ih; y++) {
        base_idx = y * n;
        for (x = 0; x < n; x++) {
            src_idx = ih * n + x;
            re_data[base_idx + x] = re_data[src_idx];
        }
    }
    for (y = 0; y < ih; y++) {
        base_idx = y * n;
        for (x = 0; x < n; x++) {
            fft_hdata[base_idx + x].im = 0.0f;
        }
    }
}
