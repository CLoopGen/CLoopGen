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
    for (int n = N; n < L; n++) {
        g[n].re = (FFTSample)(0.F + 1.0F * 0.F);
        g[n].im = (FFTSample)(0.F + 1.0F * 0.F);
        g[n].re += (g[n].re * 0.F) - (g[n].re * 0.F);
        g[n].im += (g[n].im * 0.F) - (g[n].im * 0.F);
    }
}
