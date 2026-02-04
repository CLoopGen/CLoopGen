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
    if ((z[j].re = (*in2) * (tcos[k]) - (*in1) * (tsin[k])), 
        (z[j].im = (*in2) * (tsin[k]) + (*in1) * (tcos[k])), 1) {
        in1 += 2;
        in2 -= 2;
    }
}
}
