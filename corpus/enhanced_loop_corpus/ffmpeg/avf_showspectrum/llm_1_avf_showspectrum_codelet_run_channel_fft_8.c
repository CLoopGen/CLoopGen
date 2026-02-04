#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern float a;
extern float b;
extern float S;
extern float c;
extern FFTComplex *g;
extern FFTComplex *h;
extern int L;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (int phase = 0; phase < stride; phase++) {
        for (int n = phase; n < L; n += stride) {
            c = g[n].re;
            S = g[n].im;
            a = c * h[n].re - S * h[n].im;
            b = S * h[n].re + c * h[n].im;
            g[n].re = a / L;
            g[n].im = b / L;
        }
    }
}
