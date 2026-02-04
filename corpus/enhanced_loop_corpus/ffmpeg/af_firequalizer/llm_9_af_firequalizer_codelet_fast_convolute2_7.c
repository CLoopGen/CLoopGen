#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern float *restrict data0;
extern float *restrict data1;
extern int nsamples;
extern FFTComplex *buf;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (k = 0; k < nsamples; k++) {
        FFTSample re_val = buf[k].re;
        FFTSample im_val = buf[k].im;
        data0[k] = im_val * im_val - re_val * re_val;
        data1[k] = 2.0f * re_val * im_val;
    }
}
