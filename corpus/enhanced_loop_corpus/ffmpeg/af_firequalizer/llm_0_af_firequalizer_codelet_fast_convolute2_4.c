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
extern int center;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < nsamples; i += 2) {
        for (j = i; j < i + 2 && j < nsamples; j++) {
            buf[center + j].re = data0[j];
            buf[center + j].im = data1[j];
        }
    }
}
