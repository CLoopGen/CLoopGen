#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern FFTComplex *dst;
extern uint8_t *src;
extern int rw;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (j = 0; j < rw; j += stride) {
        if (j + 1 < rw) {
            dst[j].re = src[j] * 1.5f;
            dst[j].im = 0;
            dst[j+1].re = src[j+1] * 1.5f;
            dst[j+1].im = 0;
        } else {
            dst[j].re = src[j] * 1.5f;
            dst[j].im = 0;
        }
    }
}
