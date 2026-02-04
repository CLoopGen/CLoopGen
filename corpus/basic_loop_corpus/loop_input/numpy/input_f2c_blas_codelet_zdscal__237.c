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

doublereal *da;
doublecomplex *zx;
integer *incx;
integer i__1;
integer i__2;
integer i__3;
doublecomplex z__1;
doublecomplex z__2;
integer i__;
integer ix;

void init_vars() {
    const size_t data_size = 1 << 20; // ~16 MB of doublecomplex data (2^20 elements)

    da = (doublereal*)malloc(sizeof(doublereal));
    zx = (doublecomplex*)malloc(data_size * sizeof(doublecomplex));
    incx = (integer*)malloc(sizeof(integer));

    if (!da || !zx || !incx) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    *da = 2.5;
    *incx = 1;

    for (size_t i = 0; i < data_size; ++i) {
        zx[i].r = sin(i);
        zx[i].i = cos(i);
    }

    i__1 = (integer)data_size;
    ix = 0;

    i__2 = 0;
    i__3 = 0;
    z__1.r = 0.0; z__1.i = 0.0;
    z__2.r = 0.0; z__2.i = 0.0;
    i__ = 0;
}