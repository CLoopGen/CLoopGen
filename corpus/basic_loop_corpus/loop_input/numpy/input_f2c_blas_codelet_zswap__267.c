#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

doublecomplex *zx;
integer *incx;
doublecomplex *zy;
integer *incy;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer ix;
integer iy;
doublecomplex ztemp;

void init_vars() {
    const size_t array_size = 64 * 1024 * 1024 / sizeof(doublecomplex); // ~512MB total for both arrays

    zx = (doublecomplex*)aligned_alloc(32, array_size * sizeof(doublecomplex));
    zy = (doublecomplex*)aligned_alloc(32, array_size * sizeof(doublecomplex));

    for (size_t i = 0; i < array_size; ++i) {
        zx[i].r = 1.0 + i * 0.001;
        zx[i].i = 0.5 - i * 0.0005;
        zy[i].r = 2.0 + i * 0.002;
        zy[i].i = 1.5 + i * 0.001;
    }

    incx = (integer*)aligned_alloc(32, sizeof(integer));
    incy = (integer*)aligned_alloc(32, sizeof(integer));

    *incx = 1;
    *incy = 1;

    i__1 = (integer)(array_size * 0.8); // ensure we don't exceed bounds
    ix = 0;
    iy = 0;
}