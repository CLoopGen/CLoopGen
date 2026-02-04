#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;
typedef int logical;

singlecomplex *a = NULL;
singlecomplex *x = NULL;
integer *incx = NULL;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
singlecomplex q__1;
singlecomplex q__2;
integer i__;
integer j;
integer ix;
integer jx;
integer kx;
singlecomplex temp;
logical nounit;

void init_vars() {
    const int size_a_dim1 = 2048;
    const int size_j = 2048;

    a_dim1 = size_a_dim1;
    i__1 = size_j;
    incx = (integer*)malloc(sizeof(integer));
    *incx = 1;
    nounit = 1;

    a = (singlecomplex*)calloc((size_a_dim1 + 1) * (size_j + 1), sizeof(singlecomplex));
    x = (singlecomplex*)calloc(size_j * abs(*incx) + 1, sizeof(singlecomplex));

    kx = 1;
    jx = 1;

    for (int idx = 0; idx < (size_a_dim1 + 1) * (size_j + 1); ++idx) {
        a[idx].r = (real)(rand() % 100) / 100.0f;
        a[idx].i = (real)(rand() % 100) / 100.0f;
    }

    for (int idx = 0; idx < size_j * abs(*incx) + 1; ++idx) {
        x[idx].r = (real)(rand() % 100) / 100.0f;
        x[idx].i = (real)(rand() % 100) / 100.0f;
    }

    temp.r = 0.0f; temp.i = 0.0f;
    i__ = 0;
    j = 1;
    ix = 1;
}