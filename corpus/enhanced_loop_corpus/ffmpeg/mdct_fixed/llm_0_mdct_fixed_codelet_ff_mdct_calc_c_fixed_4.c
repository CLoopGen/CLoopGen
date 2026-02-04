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
for (i = 0; i < n8; i++) {
    FFTSample r0, i0, r1, i1;
    i1 = ((x[n8 - i - 1].re * (-tsin[n8 - i - 1])) - (x[n8 - i - 1].im * (-tcos[n8 - i - 1]))) >> 15;
    r0 = ((x[n8 - i - 1].re * (-tcos[n8 - i - 1])) + (x[n8 - i - 1].im * (-tsin[n8 - i - 1]))) >> 15;
    i0 = ((x[n8 + i].re * (-tsin[n8 + i])) - (x[n8 + i].im * (-tcos[n8 + i]))) >> 15;
    r1 = ((x[n8 + i].re * (-tcos[n8 + i])) + (x[n8 + i].im * (-tsin[n8 + i]))) >> 15;
    x[n8 - i - 1].re = r0;
    x[n8 - i - 1].im = i0;
    x[n8 + i].re = r1;
    x[n8 + i].im = i1;
}
}
