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
        // Process two iterations at once to increase computational intensity
        float c1 = g[n].re, s1 = g[n].im;
        float c2 = g[n+1].re, s2 = g[n+1].im;

        a = c1 * h[n].re - s1 * h[n].im;
        b = s1 * h[n].re + c1 * h[n].im;
        g[n].re = a / L;
        g[n].im = b / L;

        a = c2 * h[n+1].re - s2 * h[n+1].im;
        b = s2 * h[n+1].re + c2 * h[n+1].im;
        g[n+1].re = a / L;
        g[n+1].im = b / L;
    } else {
        // Handle leftover element
        c = g[n].re;
        S = g[n].im;
        a = c * h[n].re - S * h[n].im;
        b = S * h[n].re + c * h[n].im;
        g[n].re = a / L;
        g[n].im = b / L;
    }
}
}
