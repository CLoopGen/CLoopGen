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
    int *indices = (int*)alloca(rw * sizeof(int));
    for (int i = 0; i < rw; i++) {
        indices[i] = rw - 1 - i; // reverse access pattern
    }
    for (j = 0; j < rw; j++) {
        int idx = indices[j];
        dst[j].re = src[idx];
        dst[j].im = 0;
    }
}
