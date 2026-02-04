#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

int k;
int n4 = 65536; // Adjusted to control data size for ~0.01 sec runtime
int j;
uint16_t *revtab;
FFTSample *tcos;
FFTSample *tsin;
FFTSample *in1;
FFTSample *in2;
FFTComplex *z;

void init_vars() {
    size_t size = n4 * sizeof(FFTComplex);
    revtab = (uint16_t*)aligned_alloc(16, n4 * sizeof(uint16_t));
    tcos = (FFTSample*)aligned_alloc(16, n4 * sizeof(FFTSample));
    tsin = (FFTSample*)aligned_alloc(16, n4 * sizeof(FFTSample));
    in1 = (FFTSample*)aligned_alloc(16, size);
    in2 = (FFTSample*)aligned_alloc(16, size);
    z = (FFTComplex*)aligned_alloc(16, size);

    for (int i = 0; i < n4; i++) {
        revtab[i] = i;
        tcos[i] = 1.0f;
        tsin[i] = 0.0f;
    }

    for (size_t i = 0; i < size / sizeof(FFTSample); i++) {
        in1[i] = 1.0f;
        in2[i] = 1.0f;
    }
}