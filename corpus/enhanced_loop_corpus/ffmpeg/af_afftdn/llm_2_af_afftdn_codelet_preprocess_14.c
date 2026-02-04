#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern FFTComplex *in;
extern int len;
extern double d1;
extern double d2;
extern double d3;
extern double d4;
extern double d6;
extern double d7;
extern double d8;
extern double d9;
extern double d10;
extern int n;
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element, reducing effective length accordingly)
    int stride = 2;
    int limit = (len / 4) / stride;
    for (i = 1; i < limit; i++) {
        int idx = i * stride;
        k = n - idx;
        d2 = 0.5 * (in[idx].re + in[k].re);
        d1 = 0.5 * (in[idx].im - in[k].im);
        d4 = 0.5 * (in[idx].im + in[k].im);
        d3 = 0.5 * (in[k].re - in[idx].re);
        in[idx].re = d2 + d9 * d4 + d6 * d3;
        in[idx].im = d1 + d9 * d3 - d6 * d4;
        in[k].re = d2 - d9 * d4 - d6 * d3;
        in[k].im = -d1 + d9 * d3 - d6 * d4;
        d10 = d9;
        d9 += d9 * d8 - d6 * d7;
        d6 += d6 * d8 + d10 * d7;
    }
}
