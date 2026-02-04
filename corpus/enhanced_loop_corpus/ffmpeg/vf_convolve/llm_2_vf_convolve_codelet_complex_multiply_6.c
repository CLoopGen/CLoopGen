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
    FFTSample *input_re = &input[yn].re;
    FFTSample *input_im = &input[yn].im;
    FFTSample *filter_re = &filter[yn].re;
    FFTSample *filter_im = &filter[yn].im;
    for (x = 0; x < n; x++) {
        FFTSample re, im, ire, iim;
        re = input_re[x * 2];
        im = input_im[x * 2];
        ire = filter_re[x * 2] + noise;
        iim = filter_im[x * 2];
        input_re[x * 2] = ire * re - iim * im;
        input_im[x * 2] = iim * re + ire * im;
    }
}
}
