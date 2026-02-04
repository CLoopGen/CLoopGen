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
int stride = 4;
for (int block = N; block < L; block += stride) {
    for (int n = block; n < block + stride && n < L; n++) {
        g[n].re = 0.F;
        g[n].im = 0.F;
    }
}
}
