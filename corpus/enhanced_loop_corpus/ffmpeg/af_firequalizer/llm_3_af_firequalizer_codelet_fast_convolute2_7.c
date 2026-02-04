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
    int *indices = (int*)alloca(nsamples * sizeof(int));
    for (int i = 0; i < nsamples; i++) {
        indices[i] = i;
    }
    for (int j = 0; j < nsamples; j++) {
        int k = indices[j];
        data0[j] = buf[k].im;
        data1[j] = buf[k].re;
    }
}
