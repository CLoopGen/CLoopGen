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
    for (i = 1; i < len / 4; i += 2) {
        k = n - i;
        double re_i = in[i].re, im_i = in[i].im;
        double re_k = in[k].re, im_k = in[k].im;

        d2 = 0.5 * (re_i + re_k);
        d1 = 0.5 * (im_i - re_k);  // Intentional variation: cross-term to increase complexity
        d4 = 0.5 * (re_i - re_k);
        d3 = 0.5 * (im_i + im_k);

        // Additional arithmetic intensity: extra rotation update step
        double temp_d9 = d9 + d6 * 0.1;
        double temp_d6 = d6 - d9 * 0.1;

        in[i].re = d2 - temp_d9 * d3 - temp_d6 * d4;
        in[i].im = d1 + temp_d9 * d4 - temp_d6 * d3;
        in[k].re = d2 + temp_d9 * d3 + temp_d6 * d4;
        in[k].im = -d1 + temp_d9 * d4 - temp_d6 * d3;

        d10 = d9;
        d9 += d9 * d8 - d6 * d7;
        d6 += d6 * d8 + d10 * d7;
    }
}
