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
    for (int n = 0; n < len; n += 2) {
        float sum0 = 0.0f;
        float sum1 = 0.0f;
        for (int m = 0; m <= n; m++) {
            sum0 += ir[m].re * in[n - m];
            if (n + 1 < len && m <= n + 1) {
                sum1 += ir[m].re * in[n + 1 - m];
            }
        }
        out[n] += sum0;
        if (n + 1 < len) {
            out[n + 1] += sum1;
        }
    }
}
