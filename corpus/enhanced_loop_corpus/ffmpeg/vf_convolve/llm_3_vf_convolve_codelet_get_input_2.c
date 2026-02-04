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
    // Variant 2: Strided memory access with reversed column iteration to modify access pattern
    for (x = n - 1; x >= 0; x--) {  // reverse column traversal
        for (y = n - ih; y < n; y++) {
            int idx = y * n + x;
            int src_idx = (n - ih - 1) * n + x;
            fft_hdata[idx].re = fft_hdata[src_idx].re;
            fft_hdata[idx].im = 0;
        }
    }
}
