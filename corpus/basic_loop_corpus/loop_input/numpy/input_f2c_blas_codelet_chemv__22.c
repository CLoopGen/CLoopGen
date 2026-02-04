#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *beta;
singlecomplex *y;
integer i__1;
integer i__2;
integer i__3;
singlecomplex q__1;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB for float complex (each 8 bytes)
    const size_t n = data_size / sizeof(singlecomplex);

    beta = (singlecomplex*)aligned_alloc(32, sizeof(singlecomplex));
    y = (singlecomplex*)aligned_alloc(32, data_size);

    if (!beta || !y) {
        exit(1);
    }

    beta->r = 1.5f;
    beta->i = -0.8f;

    for (size_t idx = 0; idx < n; ++idx) {
        y[idx].r = sinf(idx % 100);
        y[idx].i = cosf(idx % 100);
    }

    i__1 = n - 1;
    i__2 = 0;
    i__3 = 0;
    i__ = 0;
    q__1.r = 0.0f;
    q__1.i = 0.0f;
}