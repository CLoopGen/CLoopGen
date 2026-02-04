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
    float temp[len];
    for (int n = 0; n < len; n++) {
        temp[n] = 0.0f;
        for (int m = 0; m <= n; m++) {
            temp[n] += ir[m].re * in[n - m];
        }
    }
    for (int n = 0; n < len; n++) {
        out[n] += temp[n];
    }
}
