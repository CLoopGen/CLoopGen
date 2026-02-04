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
    for (j = 0; j < rw; j++) {
        FFTSample val = (FFTSample)(src[j] + 128);
        dst[j].re = val * val;
        dst[j].im = val * 0.1f;
    }
}
