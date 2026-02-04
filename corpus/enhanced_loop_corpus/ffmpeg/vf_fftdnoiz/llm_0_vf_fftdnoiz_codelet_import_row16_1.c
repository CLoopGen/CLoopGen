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
for (int k = 0; k < rw; k += 2) {
    for (j = k; j < k + 2 && j < rw; j++) {
        dst[j].re = src[j];
        dst[j].im = 0;
    }
}
}
