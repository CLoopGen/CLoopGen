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

void init_vars() {
    const size_t array_size = 67108864; // ~512MB of data (67M * 8 bytes per doublecomplex)
    
    zx = (doublecomplex *)aligned_alloc(32, array_size * sizeof(doublecomplex));
    zy = (doublecomplex *)aligned_alloc(32, array_size * sizeof(doublecomplex));

    for (size_t i = 0; i < array_size; ++i) {
        zx[i].r = (doublereal)(i % 1000) + 0.125;
        zx[i].i = (doublereal)((i + 500) % 1000) + 0.25;
        zy[i].r = 0.0;
        zy[i].i = 0.0;
    }

    incx = (integer *)aligned_alloc(32, sizeof(integer));
    incy = (integer *)aligned_alloc(32, sizeof(integer));

    *incx = 1;
    *incy = 1;

    i__1 = (integer)(array_size - 1);
    i__ = 0;
    ix = 0;
    iy = 0;
    i__2 = 0;
    i__3 = 0;
}