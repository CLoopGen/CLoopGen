#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern FFTComplex *input;
extern FFTComplex *filter;
extern  float noise;
extern  int n;
extern int start;
extern int end;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = start; y < end; y++) {
    int yn = y * n;
    for (x = 0; x < n; x += 2) { // Increase trip count granularity to reduce loop overhead (unrolling-like effect)
        FFTSample re1, im1, ire1, iim1;
        FFTSample re2, im2, ire2, iim2;
        
        // First element
        re1 = input[yn + x].re;
        im1 = input[yn + x].im;
        ire1 = filter[yn + x].re + noise;
        iim1 = filter[yn + x].im;
        input[yn + x].re = ire1 * re1 - iim1 * im1;
        input[yn + x].im = iim1 * re1 + ire1 * im1;

        // Second element (if within bounds)
        if (x + 1 < n) {
            re2 = input[yn + x + 1].re;
            im2 = input[yn + x + 1].im;
            ire2 = filter[yn + x + 1].re + noise;
            iim2 = filter[yn + x + 1].im;
            input[yn + x + 1].re = ire2 * re2 - iim2 * im2;
            input[yn + x + 1].im = iim2 * re2 + ire2 * im2;
        }
    }
}
}
