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
integer i__1;
integer i__2;
integer i__3;
singlecomplex q__1;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements to target ~0.01 sec runtime
    y = (singlecomplex*)aligned_alloc(32, data_size * sizeof(singlecomplex));
    beta = (singlecomplex*)aligned_alloc(32, sizeof(singlecomplex));

    if (!y || !beta) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        y[idx].r = (real)(idx % 100) / 100.0f;
        y[idx].i = (real)((idx + 10) % 100) / 100.0f;
    }

    beta->r = 1.5f;
    beta->i = 0.8f;

    i__1 = (integer)(data_size - 1); 
    i__2 = 0;
    i__3 = 0;
    i__ = 0;
    q__1.r = 0.0f;
    q__1.i = 0.0f;
}