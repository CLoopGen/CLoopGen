#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern FFTComplex *h;
extern int L;
extern int M;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FFTSample *re = &h[M].re;
    FFTSample *im = &h[M].im;
    int len = L - M;
    for (int i = 0; i < len; i++) {
        re[i] = 0.F;
        im[i] = 0.F;
    }
}
