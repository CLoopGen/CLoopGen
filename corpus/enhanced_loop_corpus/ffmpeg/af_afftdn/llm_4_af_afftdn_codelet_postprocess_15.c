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
for (i = 1; i < len / 4; i++) {
    k = n - i;
    FFTSample re_i = in[i].re;
    FFTSample im_i = in[i].im;
    FFTSample re_k = in[k].re;
    FFTSample im_k = in[k].im;
    
    d2 = 0.5 * (re_i + re_k);
    d1 = 0.5 * (im_i - im_k);
    d4 = 0.5 * (re_i - re_k);
    d3 = 0.5 * (im_i + im_k);
    
    in[i].re = d2 - d9 * d3 - d6 * d4;
    in[i].im = d1 + d9 * d4 - d6 * d3;
    in[k].re = d2 + d9 * d3 + d6 * d4;
    in[k].im = -d1 + d9 * d4 - d6 * d3;
    
    double temp_d9 = d9;
    d9 += d9 * d8 - d6 * d7;
    d6 += d6 * d8 + temp_d9 * d7;
}
}
