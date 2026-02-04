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
    data0[k] = buf[k].im;
    data1[k] = buf[k].re;
}

}
