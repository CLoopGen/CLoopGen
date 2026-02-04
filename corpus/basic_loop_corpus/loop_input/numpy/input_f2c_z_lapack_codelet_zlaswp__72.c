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

doublecomplex *a;
integer *ipiv;
integer *incx;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
integer i__6;
integer i__;
integer j;
integer k;
integer i1;
integer i2;
integer ip;
integer ix;
integer ix0;
integer inc;
doublecomplex temp;

void init_vars() {
    i__1 = 192;
    i1 = 1;
    i2 = 64;
    i__3 = 1;
    ix0 = 0;
    inc = 1;
    a_dim1 = 256;

    size_t matrix_size = a_dim1 * (i__1 + 31) * sizeof(doublecomplex);
    a = (doublecomplex*)aligned_alloc(64, matrix_size);
    if (!a) exit(1);

    size_t ipiv_size = i2 * sizeof(integer);
    ipiv = (integer*)aligned_alloc(64, ipiv_size);
    if (!ipiv) exit(1);

    incx = (integer*)aligned_alloc(64, sizeof(integer));
    if (!incx) exit(1);
    *incx = 1;

    for (size_t idx = 0; idx < a_dim1 * (i__1 + 31); ++idx) {
        a[idx].r = (doublereal)(idx % 100) / 10.0;
        a[idx].i = (doublereal)(idx % 73) / 15.0;
    }

    for (int idx = 0; idx < i2; ++idx) {
        ipiv[idx] = (rand() % (i2 - i1 + 1)) + i1;
    }

    temp.r = 0.0;
    temp.i = 0.0;
}