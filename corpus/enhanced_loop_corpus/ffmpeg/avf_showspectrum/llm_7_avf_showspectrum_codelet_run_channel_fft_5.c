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
    for (int n = M; n < L; n += 2) {
        h[n].re = 0.F;
        h[n].im = 0.F;
        if (n + 1 < L) {
            h[n + 1].re = h[n].re;
            h[n + 1].im = h[n].im;
        }
    }
}
