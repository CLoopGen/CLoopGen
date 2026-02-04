#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *beta;
singlecomplex *y;
integer *incy;
integer i__1;
integer i__2;
integer i__3;
singlecomplex q__1;
integer i__;
integer iy;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024 / sizeof(singlecomplex); // ~256MB total for y
    i__1 = data_size - 1;
    iy = 0;
    incy = (integer*)malloc(sizeof(integer));
    *incy = 1;

    beta = (singlecomplex*)malloc(sizeof(singlecomplex));
    beta->r = 1.5f;
    beta->i = 0.8f;

    y = (singlecomplex*)calloc(data_size, sizeof(singlecomplex));
    if (!y || !beta || !incy) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        y[idx].r = (real)(idx % 128) / 128.0f;
        y[idx].i = (real)((idx + 1) % 128) / 128.0f;
    }
}