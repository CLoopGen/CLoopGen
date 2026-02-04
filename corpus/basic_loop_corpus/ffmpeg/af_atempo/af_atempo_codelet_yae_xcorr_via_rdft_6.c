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
for (i = 1; i < window; i++ , xa++ , xb++ , xc++) {
    xc->re = (xa->re * xb->re + xa->im * xb->im);
    xc->im = (xa->im * xb->re - xa->re * xb->im);
}

}
