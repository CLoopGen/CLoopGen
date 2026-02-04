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
    FFTComplex *xa_local = xa;
    FFTComplex *xb_local = xb;
    FFTComplex *xc_local = xc;
    int i_local = 1;
    FFTSample temp_re, temp_im;
    for (; i_local < window; i_local++) {
        temp_re = (xa_local->re * xb_local->re + xa_local->im * xb_local->im);
        temp_im = (xa_local->im * xb_local->re - xa_local->re * xb_local->im);
        xc_local->re = temp_re;
        xc_local->im = temp_im;
        xa_local++;
        xb_local++;
        xc_local++;
    }
    xa = xa_local;
    xb = xb_local;
    xc = xc_local;
    i = i_local;
}
