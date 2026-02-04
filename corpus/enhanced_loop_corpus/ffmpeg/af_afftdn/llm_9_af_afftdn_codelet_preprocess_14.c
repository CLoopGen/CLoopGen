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
    d2 = 0.5 * (in[i].re + in[k].re);
    d1 = 0.5 * (in[i].im - in[k].im);
    d4 = 0.5 * (in[i].im + in[k].im);
    d3 = 0.5 * (in[k].re - in[i].re);
    in[i].re = d2 + d9 * d4 + d6 * d3;
    in[i].im = d1 + d9 * d3 - d6 * d4;
    in[k].re = d2 - d9 * d4 - d6 * d3;
    in[k].im = -d1 + d9 * d3 - d6 * d4;

    if (i + 1 < len / 4) {
        int i2 = i + 1;
        int k2 = n - i2;
        double d2_2 = 0.5 * (in[i2].re + in[k2].re);
        double d1_2 = 0.5 * (in[i2].im - in[k2].im);
        double d4_2 = 0.5 * (in[i2].im + in[k2].im);
        double d3_2 = 0.5 * (in[k2].re - in[i2].re);
        in[i2].re = d2_2 + d9 * d4_2 + d6 * d3_2;
        in[i2].im = d1_2 + d9 * d3_2 - d6 * d4_2;
        in[k2].re = d2_2 - d9 * d4_2 - d6 * d3_2;
        in[k2].im = -d1_2 + d9 * d3_2 - d6 * d4_2;
    }

    d10 = d9;
    d9 += d9 * d8 - d6 * d7;
    d6 += d6 * d8 + d10 * d7;
}
}
