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



void loop() {
    for (i = 0; i < n8; i++) {
        FFTSample r0, i0, r1, i1;
        int idx1 = n8 - i - 1;
        int idx2 = n8 + i;

        // Variant 1: Reverse memory access order and use consecutive-like indexing via pointer arithmetic
        FFTComplex *x1 = &x[idx1];
        FFTComplex *x2 = &x[idx2];

        i1 = ((x1->re * (-tsin[idx1])) - (x1->im * (-tcos[idx1]))) >> 15;
        r0 = ((x1->re * (-tcos[idx1])) + (x1->im * (-tsin[idx1]))) >> 15;

        i0 = ((x2->re * (-tsin[idx2])) - (x2->im * (-tcos[idx2]))) >> 15;
        r1 = ((x2->re * (-tcos[idx2])) + (x2->im * (-tsin[idx2]))) >> 15;

        x1->re = r0;
        x1->im = i0;
        x2->re = r1;
        x2->im = i1;
    }
}
