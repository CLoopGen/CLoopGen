#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

FFTComplex *g = NULL;
int L = 0;
int N = 0;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64 million bytes (~256 MB for complex floats: 2 floats per element)
    size_t num_elements = data_size / sizeof(FFTComplex);

    g = aligned_alloc(32, num_elements * sizeof(FFTComplex));
    if (!g) exit(1);

    for (size_t i = 0; i < num_elements; ++i) {
        g[i].re = 1.0f;
        g[i].im = 1.0f;
    }

    N = num_elements / 2;
    L = num_elements;

    if (N >= L) exit(1);
}