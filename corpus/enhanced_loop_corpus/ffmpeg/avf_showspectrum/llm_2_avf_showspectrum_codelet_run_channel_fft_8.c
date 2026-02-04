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
for (int n = 0; n < L; n += 2) {
    if (n + 1 < L) {
        c = g[n].re;
        S = g[n].im;
        a = c * h[n].re - S * h[n].im;
        b = S * h[n].re + c * h[n].im;
        g[n].re = a / L;
        g[n].im = b / L;

        c = g[n+1].re;
        S = g[n+1].im;
        a = c * h[n+1].re - S * h[n+1].im;
        b = S * h[n+1].re + c * h[n+1].im;
        g[n+1].re = a / L;
        g[n+1].im = b / L;
    } else {
        c = g[n].re;
        S = g[n].im;
        a = c * h[n].re - S * h[n].im;
        b = S * h[n].re + c * h[n].im;
        g[n].re = a / L;
        g[n].im = b / L;
    }
}
}
