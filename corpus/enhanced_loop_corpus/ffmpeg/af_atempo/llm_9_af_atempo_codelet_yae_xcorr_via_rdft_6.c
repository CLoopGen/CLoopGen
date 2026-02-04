#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern  FFTComplex *xa;
extern  FFTComplex *xb;
extern  int window;
extern FFTComplex *xc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < window; i += 2, xa += 2, xb += 2, xc += 2) {
    xc[0].re = (xa[0].re * xb[0].re + xa[0].im * xb[0].im);
    xc[0].im = (xa[0].im * xb[0].re - xa[0].re * xb[0].im);
    xc[1].re = (xa[1].re * xb[1].re + xa[1].im * xb[1].im);
    xc[1].im = (xa[1].im * xb[1].re - xa[1].re * xb[1].im);
}
}
