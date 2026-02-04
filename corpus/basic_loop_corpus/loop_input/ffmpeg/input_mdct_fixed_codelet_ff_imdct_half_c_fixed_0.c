#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

typedef int16_t FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

int k;
int n4 = 65536;
int j;

uint16_t *revtab;
FFTSample *tcos;
FFTSample *tsin;
FFTSample *in1;
FFTSample *in2;
FFTComplex *z;

void init_vars() {
    const size_t data_size = 1 << 18; // ~512KB of complex data
    const size_t num_elements = data_size / sizeof(FFTComplex);

    n4 = num_elements / 4; // ensure we stay within bounds

    revtab = (uint16_t*)aligned_alloc(32, n4 * sizeof(uint16_t));
    tcos = (FFTSample*)aligned_alloc(32, n4 * sizeof(FFTSample));
    tsin = (FFTSample*)aligned_alloc(32, n4 * sizeof(FFTSample));
    in1 = (FFTSample*)aligned_alloc(32, n4 * 2 * sizeof(FFTSample));
    in2 = (FFTSample*)aligned_alloc(32, n4 * 2 * sizeof(FFTSample));
    z = (FFTComplex*)aligned_alloc(32, num_elements * sizeof(FFTComplex));

    for (int i = 0; i < n4; i++) {
        revtab[i] = (uint16_t)(i % num_elements);
        tcos[i] = (FFTSample)(0x7FFF * (double)(i + 1) / (n4 + 1));
        tsin[i] = (FFTSample)(0x7FFF * (double)(i + 1) / (n4 + 1));
    }

    for (int i = 0; i < n4 * 2; i++) {
        in1[i] = (FFTSample)(0x7FFF * (double)(i + 1) / (n4 * 2 + 1));
        in2[i] = (FFTSample)(0x7FFF * (double)(i + 1) / (n4 * 2 + 1));
    }

    for (size_t i = 0; i < num_elements; i++) {
        z[i].re = 0;
        z[i].im = 0;
    }

    in1 += 0;
    in2 += n4 * 2 - 1;
}