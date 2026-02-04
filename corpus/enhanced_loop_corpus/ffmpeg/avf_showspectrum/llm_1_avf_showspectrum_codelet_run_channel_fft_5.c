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
    if (M < L) {
        for (int outer = M; outer < L; outer += 1) {
            int n = outer;
            h[n].re = 0.F;
            h[n].im = 0.F;
        }
    }
}
