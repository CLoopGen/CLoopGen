#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern  float *in;
extern  FFTComplex *ir;
extern int len;
extern float *out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int m = 0; m < len; m++) {
        FFTSample ir_re = ir[m].re;
        for (int n = m; n < len; n++) {
            out[n] += ir_re * in[n - m];
        }
    }
}
