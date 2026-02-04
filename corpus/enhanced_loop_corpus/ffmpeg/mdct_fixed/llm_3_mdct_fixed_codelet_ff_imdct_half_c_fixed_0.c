#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int16_t FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern int k;
extern int n4;
extern int j;
extern  uint16_t *revtab;
extern  FFTSample *tcos;
extern  FFTSample *tsin;
extern  FFTSample *in1;
extern  FFTSample *in2;
extern FFTComplex *z;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (k = 0; k < n4; k++) {
        j = revtab[k];
        int stride = 4;
        int offset = k * stride;
        z[j].re = (((in2[-offset + (2 * n4) - 2] * tcos[k]) - (in1[offset] * tsin[k]))) >> 15;
        z[j].im = (((in2[-offset + (2 * n4) - 2] * tsin[k]) + (in1[offset] * tcos[k]))) >> 15;
    }
}
