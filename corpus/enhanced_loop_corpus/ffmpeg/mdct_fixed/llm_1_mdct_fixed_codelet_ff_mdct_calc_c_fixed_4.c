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
if (n8 > 0) {
    for (i = 0; i < n8; i += 2) {
        FFTSample r0, i0, r1, i1;
        // First iteration of unrolled loop (i)
        i1 = ((x[n8 - i - 1].re * (-tsin[n8 - i - 1])) - (x[n8 - i - 1].im * (-tcos[n8 - i - 1]))) >> 15;
        r0 = ((x[n8 - i - 1].re * (-tcos[n8 - i - 1])) + (x[n8 - i - 1].im * (-tsin[n8 - i - 1]))) >> 15;
        i0 = ((x[n8 + i].re * (-tsin[n8 + i])) - (x[n8 + i].im * (-tcos[n8 + i]))) >> 15;
        r1 = ((x[n8 + i].re * (-tcos[n8 + i])) + (x[n8 + i].im * (-tsin[n8 + i]))) >> 15;
        x[n8 - i - 1].re = r0;
        x[n8 - i - 1].im = i0;
        x[n8 + i].re = r1;
        x[n8 + i].im = i1;

        // Second iteration of unrolled loop (i+1), with bounds check
        if (i + 1 < n8) {
            int j = i + 1;
            i1 = ((x[n8 - j - 1].re * (-tsin[n8 - j - 1])) - (x[n8 - j - 1].im * (-tcos[n8 - j - 1]))) >> 15;
            r0 = ((x[n8 - j - 1].re * (-tcos[n8 - j - 1])) + (x[n8 - j - 1].im * (-tsin[n8 - j - 1]))) >> 15;
            i0 = ((x[n8 + j].re * (-tsin[n8 + j])) - (x[n8 + j].im * (-tcos[n8 + j]))) >> 15;
            r1 = ((x[n8 + j].re * (-tcos[n8 + j])) + (x[n8 + j].im * (-tsin[n8 + j]))) >> 15;
            x[n8 - j - 1].re = r0;
            x[n8 - j - 1].im = i0;
            x[n8 + j].re = r1;
            x[n8 + j].im = i1;
        }
    }
}
}
