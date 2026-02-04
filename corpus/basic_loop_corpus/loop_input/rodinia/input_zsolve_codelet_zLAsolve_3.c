#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double re;
    double im;
} complex;

u_int dim = 16777216; // ~134MB of data (16M * 8 bytes * 2)
int i;
complex *b_ve;

void init_vars() {
    b_ve = (complex *)aligned_alloc(32, dim * sizeof(complex));
    if (!b_ve) {
        exit(1);
    }

    for (u_int idx = 0; idx < dim; idx++) {
        b_ve[idx].re = 0.0;
        b_ve[idx].im = 0.0;
    }

    // Set last few elements to non-zero to ensure loop runs through most of the array
    int trail = dim > 10 ? 10 : dim;
    for (int j = 0; j < trail; j++) {
        b_ve[dim - 1 - j].re = 1.0;
        b_ve[dim - 1 - j].im = 1.0;
    }
}