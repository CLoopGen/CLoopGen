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
    for (i = 1; i < window; i++, xa++, xb++, xc++) {
        float re_a = xa->re, im_a = xa->im;
        float re_b = xb->re, im_b = xb->im;
        if (re_a != 0.0f || im_a != 0.0f || re_b != 0.0f || im_b != 0.0f) {
            xc->re = (re_a * re_b + im_a * im_b);
            xc->im = (im_a * re_b - re_a * im_b);
        } else {
            xc->re = 0.0f;
            xc->im = 0.0f;
        }
    }
}
