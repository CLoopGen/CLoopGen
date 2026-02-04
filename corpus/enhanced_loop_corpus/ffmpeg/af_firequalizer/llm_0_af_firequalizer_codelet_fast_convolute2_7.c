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
    for (i = 0; i < nsamples; i += 2) {
        if (i + 1 < nsamples) {
            data0[i] = buf[i].im;
            data1[i] = buf[i].re;
            data0[i+1] = buf[i+1].im;
            data1[i+1] = buf[i+1].re;
        } else {
            data0[i] = buf[i].im;
            data1[i] = buf[i].re;
        }
    }
}
