#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern FFTComplex *g;
extern int L;
extern int N;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FFTComplex *temp_g = g;
    int temp_N = N;
    int temp_L = L;
    for (int n = temp_N; n < temp_L; n++) {
        temp_g[n].re = 0.F;
        temp_g[n].im = 0.F;
    }
}
