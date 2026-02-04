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
    FFTSample temp_re, temp_im;
    for (k = 0; k < n4; k++) {
        j = revtab[k];
        temp_re = (((in2[0]) * (tcos[k])) - ((in1[0]) * (tsin[k]))) >> 15;
        temp_im = (((in2[0]) * (tsin[k])) + ((in1[0]) * (tcos[k]))) >> 15;
        z[j].re = temp_re;
        z[j].im = temp_im;
        in1 += 2;
        in2 -= 2;
    }
}
