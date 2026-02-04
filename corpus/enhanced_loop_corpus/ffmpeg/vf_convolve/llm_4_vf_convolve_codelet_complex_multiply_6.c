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
    for (x = 0; x < n; x++) {
        FFTSample re, im, ire, iim;
        re = input[yn + x].re;
        im = input[yn + x].im;
        ire = filter[yn + x].re + noise;
        iim = filter[yn + x].im;
        if (!(re == 0.0f && im == 0.0f)) {
            input[yn + x].re = ire * re - iim * im;
            input[yn + x].im = iim * re + ire * im;
        }
    }
}
}
