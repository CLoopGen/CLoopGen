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
    for (int outer = 0; outer < 1; outer++) {
        for (int n = 0; n < L; n++) {
            c = g[n].re;
            S = g[n].im;
            a = c * h[n].re - S * h[n].im;
            b = S * h[n].re + c * h[n].im;
            g[n].re = a / L;
            g[n].im = b / L;
        }
    }
}
