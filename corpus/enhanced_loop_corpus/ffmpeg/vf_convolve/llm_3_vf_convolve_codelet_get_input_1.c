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
    // Variant 2: Strided memory access - process columns first, then rows (transposed traversal)
    for (x = 0; x < n; x++) {
        FFTSample val = fft_hdata[ih * n + x].re;
        for (y = 0; y < ih; y++) {
            int index = y * n + x;
            fft_hdata[index].re = val;
            fft_hdata[index].im = 0;
        }
    }
}
