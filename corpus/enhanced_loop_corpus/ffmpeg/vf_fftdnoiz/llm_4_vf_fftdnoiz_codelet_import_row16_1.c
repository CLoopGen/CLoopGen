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
    for (j = 0; j < rw; j++) {
        if (src[j] > 0) {
            dst[j].re = src[j];
            dst[j].im = 0;
        } else {
            dst[j].re = 0;
            dst[j].im = 0;
        }
    }
}
