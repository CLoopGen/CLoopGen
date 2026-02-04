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
    int j;
    for (j = 0; j < nsamples; j++) {
        for (int inner = 0; inner < 1; inner++) { // Artificial nesting with depth 2
            data0[j] = buf[j].im;
            data1[j] = buf[j].re;
        }
    }
}
