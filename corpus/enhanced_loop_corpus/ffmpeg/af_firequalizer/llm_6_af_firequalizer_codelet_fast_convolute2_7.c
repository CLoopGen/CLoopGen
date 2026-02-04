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
    float temp_re, temp_im;
    for (k = 0; k < nsamples; k++) {
        temp_im = buf[k].im;
        temp_re = buf[k].re;
        data0[k] = temp_im;
        data1[k] = temp_re;
    }
}
