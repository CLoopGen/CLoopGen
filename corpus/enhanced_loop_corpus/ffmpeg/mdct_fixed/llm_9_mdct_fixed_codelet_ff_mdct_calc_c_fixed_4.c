#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int16_t FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern int i;
extern int n8;
extern  FFTSample *tcos;
extern  FFTSample *tsin;
extern FFTComplex *x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int limit = n8 >> 2;
for (i = 0; i < limit; i++) {
    FFTSample r0, i1;
    int j = n8 - 2*i - 1;
    int k = n8 + 2*i;

    r0 = ((x[j].re * -tcos[j]) + (x[j].im * -tsin[j])) >> 15;
    i1 = ((x[j].re * -tsin[j]) - (x[j].im * -tcos[j])) >> 15;

    x[j].re = r0;
    x[j].im = i1;

    r0 = ((x[k].re * -tcos[k]) + (x[k].im * -tsin[k])) >> 15;
    i1 = ((x[k].re * -tsin[k]) - (x[k].im * -tcos[k])) >> 15;

    x[k].re = r0;
    x[k].im = i1;
}
}
