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
double prev_d9 = d9;
double prev_d6 = d6;
for (i = 1; i < len / 4; i++) {
    k = n - i;
    d2 = 0.5 * (in[i].re + in[k].re);
    d1 = 0.5 * (in[i].im - in[k].im);
    d4 = 0.5 * (in[i].re - in[k].re);
    d3 = 0.5 * (in[i].im + in[k].im);
    
    in[i].re = d2 - prev_d9 * d3 - prev_d6 * d4;
    in[i].im = d1 + prev_d9 * d4 - prev_d6 * d3;
    in[k].re = d2 + prev_d9 * d3 + prev_d6 * d4;
    in[k].im = -d1 + prev_d9 * d4 - prev_d6 * d3;
    
    double new_d9 = prev_d9 + prev_d9 * d8 - prev_d6 * d7;
    double new_d6 = prev_d6 + prev_d6 * d8 + prev_d9 * d7;
    prev_d9 = new_d9;
    prev_d6 = new_d6;
}
d9 = prev_d9;
d6 = prev_d6;
}
