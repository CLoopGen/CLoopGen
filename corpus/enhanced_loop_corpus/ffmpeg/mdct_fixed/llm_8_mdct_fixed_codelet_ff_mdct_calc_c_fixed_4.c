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
for (i = 0; i < n8; i += 2) {
    FFTSample r0, i0, r1, i1;
    int idx1 = n8 - i - 1;
    int idx2 = n8 + i;

    r0 = ((x[idx1].re * -tcos[idx1]) + (x[idx1].im * -tsin[idx1])) >> 15;
    i0 = ((x[idx2].re * -tsin[idx2]) - (x[idx2].im * -tcos[idx2])) >> 15;
    r1 = ((x[idx2].re * -tcos[idx2]) + (x[idx2].im * -tsin[idx2])) >> 15;
    i1 = ((x[idx1].re * -tsin[idx1]) - (x[idx1].im * -tcos[idx1])) >> 15;

    x[idx1].re = r0;
    x[idx1].im = i1;
    x[idx2].re = r1;
    x[idx2].im = i0;

    if (i + 1 < n8) {
        int idx1_next = n8 - i - 2;
        int idx2_next = n8 + i + 1;

        r0 = ((x[idx1_next].re * -tcos[idx1_next]) + (x[idx1_next].im * -tsin[idx1_next])) >> 15;
        i0 = ((x[idx2_next].re * -tsin[idx2_next]) - (x[idx2_next].im * -tcos[idx2_next])) >> 15;
        r1 = ((x[idx2_next].re * -tcos[idx2_next]) + (x[idx2_next].im * -tsin[idx2_next])) >> 15;
        i1 = ((x[idx1_next].re * -tsin[idx1_next]) - (x[idx1_next].im * -tcos[idx1_next])) >> 15;

        x[idx1_next].re = r0;
        x[idx1_next].im = i1;
        x[idx2_next].re = r1;
        x[idx2_next].im = i0;
    }
}
}
