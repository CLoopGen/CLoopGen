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
    int stride = (n > 8) ? n / 4 : 1;
    for (y = 0; y < ih; y += 2) {
        for (x = 0; x < n; x++) {
            int base_idx = y * n + x;
            int src_idx = ih * n + x;
            FFTSample re_val = fft_hdata[src_idx].re;
            fft_hdata[base_idx].re = re_val;
            fft_hdata[base_idx].im = 0;

            if (y + 1 < ih) {
                int next_idx = (y + 1) * n + x;
                fft_hdata[next_idx].re = re_val;
                fft_hdata[next_idx].im = 0;
            }

            x += stride - 1;
        }
    }
}
