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
    int k;
    FFTSample scale = 1.0f / (nsamples > 0 ? (float)nsamples : 1.0f);
    for (k = 0; k < nsamples; k++) {
        FFTSample re_val = data0[k] * scale;
        FFTSample im_val = data1[k] * scale;
        buf[center + k].re = re_val;
        buf[center + k].im = im_val;
        buf[center + k].re += re_val * 0.1f;
        buf[center + k].im -= im_val * 0.1f;
    }
}
