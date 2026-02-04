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
        int index_cos = k;
        int index_sin = k;
        int index_in1 = 2 * k;
        int index_in2 = 2 * (n4 - 1 - k);
        z[j].re = ((in2[index_in2] * tcos[index_cos]) - (in1[index_in1] * tsin[index_sin])) >> 15;
        z[j].im = ((in2[index_in2] * tsin[index_sin]) + (in1[index_in1] * tcos[index_cos])) >> 15;
    }
}
