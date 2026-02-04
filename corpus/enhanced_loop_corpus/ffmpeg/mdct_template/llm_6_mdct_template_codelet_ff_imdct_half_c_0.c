#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

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
        FFTSample c = tcos[k];
        FFTSample s = tsin[k];
        FFTSample in1_val = in1[0];
        FFTSample in2_val = in2[0];
        z[j].re = in2_val * c - in1_val * s;
        z[j].im = in2_val * s + in1_val * c;
        in1 += 2;
        in2 -= 2;
    }
}
