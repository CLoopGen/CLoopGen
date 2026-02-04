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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing elements symmetrically from the front and back (i and n-i),
    // we now process elements with a fixed stride of 2, still maintaining symmetry within the stride.
    // This changes spatial locality and access pattern while preserving logic via index remapping.
    int stride = 2;
    for (i = stride; i < len / 4; i += stride) {
        k = n - i;
        d2 = 0.5 * (in[i].re + in[k].re);
        d1 = 0.5 * (in[i].im - in[k].im);
        d4 = 0.5 * (in[i].re - in[k].re);
        d3 = 0.5 * (in[i].im + in[k].im);
        in[i].re = d2 - d9 * d3 - d6 * d4;
        in[i].im = d1 + d9 * d4 - d6 * d3;
        in[k].re = d2 + d9 * d3 + d6 * d4;
        in[k].im = -d1 + d9 * d4 - d6 * d3;
        d10 = d9;
        d9 += d9 * d8 - d6 * d7;
        d6 += d6 * d8 + d10 * d7;
    }
    // Handle remaining element if needed to preserve behavior (compensate for stride skip)
    if ((len / 4) % 2 == 1 && (len / 4) > 0) {
        i = 1;
        k = n - i;
        d2 = 0.5 * (in[i].re + in[k].re);
        d1 = 0.5 * (in[i].im - in[k].im);
        d4 = 0.5 * (in[i].re - in[k].re);
        d3 = 0.5 * (in[i].im + in[k].im);
        in[i].re = d2 - d9 * d3 - d6 * d4;
        in[i].im = d1 + d9 * d4 - d6 * d3;
        in[k].re = d2 + d9 * d3 + d6 * d4;
        in[k].im = -d1 + d9 * d4 - d6 * d3;
        d10 = d9;
        d9 += d9 * d8 - d6 * d7;
        d6 += d6 * d8 + d10 * d7;
    }
}
