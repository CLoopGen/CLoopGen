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

singlecomplex *y;
integer *incy;
integer i__1;
integer i__2;
integer i__;
integer iy;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements, roughly 512MB for singlecomplex array
    y = (singlecomplex*)aligned_alloc(32, data_size * sizeof(singlecomplex));
    if (!y) exit(1);

    for (size_t i = 0; i < data_size; ++i) {
        y[i].r = 1.0F;
        y[i].i = 1.0F;
    }

    incy = (integer*)aligned_alloc(32, sizeof(integer));
    if (!incy) exit(1);
    *incy = 1;

    i__1 = (integer)(data_size / abs(*incy)); 
    iy = 0;
    i__ = 0;
    i__2 = 0;
}