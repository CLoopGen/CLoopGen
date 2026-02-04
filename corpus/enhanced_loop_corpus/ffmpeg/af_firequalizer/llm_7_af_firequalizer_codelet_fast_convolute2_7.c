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
    for (k = 0; k < nsamples; k++) {
        data1[k] = buf[k].re;
        data0[k] = buf[k].im;
    }
    // Introduces a WAW-like potential if called repeatedly, but no loop-carried dependency.
    // Reordered assignments to modify write order (WAR/RAR pattern altered),
    // changing the data dependency chain without affecting final result.
}
