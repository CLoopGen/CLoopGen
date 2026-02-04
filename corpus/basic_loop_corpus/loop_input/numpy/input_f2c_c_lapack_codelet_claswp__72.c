#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *a;
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
singlecomplex temp;

void init_vars() {
    a_dim1 = 1024;
    i__1 = 960;
    i1 = 1;
    i2 = 32;
    inc = 1;
    ix0 = 0;
    incx = (integer*)malloc(sizeof(integer));
    *incx = 1;

    size_t a_size = (size_t)(a_dim1 + 1) * (i__1 + 31);
    a = (singlecomplex*)calloc(a_size, sizeof(singlecomplex));
    for (size_t idx = 0; idx < a_size; ++idx) {
        a[idx].r = (real)(idx % 100) / 100.0f;
        a[idx].i = (real)(idx % 75) / 100.0f;
    }

    size_t ipiv_size = i2 + 1;
    ipiv = (integer*)malloc(ipiv_size * sizeof(integer));
    for (int idx = 0; idx <= i2; ++idx) {
        ipiv[idx] = idx;
    }
    for (int idx = i1; idx <= i2; idx += 5) {
        if (idx + 2 <= i2) {
            ipiv[ix0 + (idx - i1)] = idx + 2;
        }
    }
}