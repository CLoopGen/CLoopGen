#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

FFTComplex *dst;
uint8_t *src;
int rw;
int j;

void init_vars() {
    rw = 1 << 24;  // Approximately 16.7 million elements, ~64MB input, suitable for ~0.01 sec on modern CPU
    src = (uint8_t *)malloc(rw * sizeof(uint8_t));
    dst = (FFTComplex *)malloc(rw * sizeof(FFTComplex));
    if (!src || !dst) {
        exit(1);
    }
    for (int i = 0; i < rw; i++) {
        src[i] = (uint8_t)(i & 0xFF);
    }
}