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
    for (int n = 0; n < len; n++) {
        float temp = 0.0f;
        for (int m = 0; m <= n; m++) {
            temp += ir[m].re * in[n - m];
        }
        if (n % 2 == 0) {
            out[n] += temp;
        } else {
            out[n] += temp * 0.9f;
        }
    }
}
