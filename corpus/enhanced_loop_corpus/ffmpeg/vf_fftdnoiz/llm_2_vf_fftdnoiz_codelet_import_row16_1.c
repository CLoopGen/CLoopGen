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
extern int rw;
extern uint16_t *src;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (j = 0; j < rw; j += stride) {
        if (j < rw) {
            dst[j].re = src[j];
            dst[j].im = 0;
        }
        int next = j + 1;
        if (next < rw) {
            dst[next].re = src[next];
            dst[next].im = 0;
        }
    }
}
