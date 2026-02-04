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



void loop(){
    for (k = 0; k < n4; k++) {
        j = revtab[k];
        FFTSample in1_val = in1[0];
        FFTSample in2_val = in2[0];
        FFTSample cos_val = tcos[k];
        FFTSample sin_val = tsin[k];
        z[j].re = ((in2_val * cos_val) - (in1_val * sin_val)) >> 15;
        z[j].im = ((in2_val * sin_val) + (in1_val * cos_val)) >> 15;
        in1 += 2;
        in2 -= 2;
    }
}
