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

doublecomplex *za;
doublecomplex *zx;
integer *incx;
integer i__1;
integer i__2;
integer i__3;
doublecomplex z__1;
integer i__;
integer ix;

void init_vars() {
    const size_t data_size = 1 << 20; // ~16 MB of doublecomplex data (2^20 elements)

    zx = (doublecomplex*)aligned_alloc(32, data_size * sizeof(doublecomplex));
    za = (doublecomplex*)aligned_alloc(32, sizeof(doublecomplex));

    incx = (integer*)malloc(sizeof(integer));

    if (!zx || !za || !incx) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        zx[i].r = sin(i * 0.01);
        zx[i].i = cos(i * 0.01);
    }

    za->r = 1.5;
    za->i = 0.8;

    *incx = 1;

    i__1 = data_size;
    ix = 0;
}