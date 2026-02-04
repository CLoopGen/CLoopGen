#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

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
doublecomplex z__1;
doublecomplex z__2;
integer i__;
integer ix;
integer iy;
doublecomplex ztemp;

void init_vars() {
    const size_t data_size = 1 << 20; // 1M elements for ~0.01 sec runtime estimate

    zx = (doublecomplex*)aligned_alloc(32, data_size * sizeof(doublecomplex));
    zy = (doublecomplex*)aligned_alloc(32, data_size * sizeof(doublecomplex));
    incx = (integer*)aligned_alloc(32, sizeof(integer));
    incy = (integer*)aligned_alloc(32, sizeof(integer));

    *incx = 1;
    *incy = 1;

    i__1 = data_size - 1; 
    ix = 0;
    iy = 0;

    ztemp.r = 0.0;
    ztemp.i = 0.0;

    for (size_t i = 0; i < data_size; ++i) {
        zx[i].r = sin(i * 0.001);
        zx[i].i = cos(i * 0.001);
        zy[i].r = cos(i * 0.0015);
        zy[i].i = sin(i * 0.0015);
    }
}