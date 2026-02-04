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
        FFTSample temp = 0.0f;
        int bound = (n & 1) ? (n / 2) : n; // Vary effective trip count based on parity
        for (int m = 0; m <= bound; m++) {
            temp += ir[m].re * in[n - m]; // Reduced number of arithmetic operations per iteration
        }
        out[n] += temp;
    }
}
