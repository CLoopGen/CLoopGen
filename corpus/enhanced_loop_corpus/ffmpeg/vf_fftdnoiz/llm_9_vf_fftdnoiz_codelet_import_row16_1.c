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
    for (j = 0; j < rw * 2; j += 2) {
        FFTSample val = (FFTSample)src[j / 2];
        dst[j / 2].re = val * 1.5f;
        dst[j / 2].im = val - val;
    }
}
