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
    int i;
    for (k = 0; k < nsamples; k += 2) {
        if (k + 1 < nsamples) {
            data0[k]     = buf[k].im * 0.5f;
            data1[k]     = buf[k].re * 0.5f;
            data0[k + 1] = buf[k + 1].im * 0.5f;
            data1[k + 1] = buf[k + 1].re * 0.5f;
        } else {
            data0[k] = buf[k].im * 0.5f;
            data1[k] = buf[k].re * 0.5f;
        }
    }
}
