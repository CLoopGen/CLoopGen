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
    for (j = 0; j < rw; j += 2) {
        dst[j].re = src[j];
        dst[j].im = 0;
        if (j + 1 < rw) {
            dst[j + 1].re = src[j + 1];
            dst[j + 1].im = 0;
        }
    }
}
