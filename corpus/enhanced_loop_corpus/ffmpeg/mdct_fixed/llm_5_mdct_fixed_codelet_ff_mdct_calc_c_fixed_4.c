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

    int index1 = n8 - i - 1;
    int index2 = n8 + i;

    if (index1 % 2 == 0) {
        i1 = ((x[index1].re * (-tsin[index1])) - (x[index1].im * (-tcos[index1]))) >> 15;
        r0 = ((x[index1].re * (-tcos[index1])) + (x[index1].im * (-tsin[index1]))) >> 15;

        i0 = ((x[index2].re * (-tsin[index2])) - (x[index2].im * (-tcos[index2]))) >> 15;
        r1 = ((x[index2].re * (-tcos[index2])) + (x[index2].im * (-tsin[index2]))) >> 15;
    } else {
        r0 = x[index1].re;
        i0 = x[index1].im;
        r1 = x[index2].re;
        i1 = x[index2].im;
    }

    x[index1].re = r0;
    x[index1].im = i0;
    x[index2].re = r1;
    x[index2].im = i1;
}
}
