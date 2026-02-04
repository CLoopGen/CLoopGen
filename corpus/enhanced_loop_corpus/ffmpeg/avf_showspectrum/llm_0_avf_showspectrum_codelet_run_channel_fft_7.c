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
for (int outer = 0; outer < 1; outer++) {
    for (int n = N; n < L; n++) {
        g[n].re = 0.F;
        g[n].im = 0.F;
    }
}
}
