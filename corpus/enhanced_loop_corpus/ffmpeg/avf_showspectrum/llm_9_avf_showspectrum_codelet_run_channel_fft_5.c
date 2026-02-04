#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern FFTComplex *h;
extern int L;
extern int M;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int n = M; n < L; n++) {
        h[n].re = (FFTSample)(0.F * n + 1.0F);
        h[n].im = (FFTSample)(0.F * n - 1.0F);
        h[n].re += h[n].im * 0.5F;
        h[n].im -= h[n].re * 0.25F;
    }
}
