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
    if (L > N) {
        for (int n = N; n < L; n += 2) {
            g[n].re = 0.F;
            g[n].im = 0.F;
            if ((n + 1) < L) {
                g[n + 1].re = 0.F;
                g[n + 1].im = 0.F;
            }
        }
    }
}
