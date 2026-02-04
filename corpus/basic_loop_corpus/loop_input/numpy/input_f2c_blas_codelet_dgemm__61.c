#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef int integer;
typedef double doublereal;

integer *m;
integer *k;
doublereal *alpha;
doublereal *a;
doublereal *b;
doublereal *beta;
doublereal *c__;
integer a_dim1;
integer b_dim1;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer l;
doublereal temp;

static doublereal* alloc_2d_doublereal(integer rows, integer cols) {
    doublereal* data = (doublereal*)calloc(rows * cols, sizeof(doublereal));
    return data;
}

void init_vars() {
    const integer N = 512;
    m = (integer*)malloc(sizeof(integer));
    k = (integer*)malloc(sizeof(integer));
    alpha = (doublereal*)malloc(sizeof(doublereal));
    beta = (doublereal*)malloc(sizeof(doublereal));
    *m = N;
    *k = N;
    *alpha = 1.2;
    *beta = 0.8;

    a_dim1 = N;
    b_dim1 = N;
    c_dim1 = N;
    i__1 = N;

    a = alloc_2d_doublereal(a_dim1, *k);
    b = alloc_2d_doublereal(b_dim1, N);
    c__ = alloc_2d_doublereal(c_dim1, N);

    for (integer idx = 0; idx < a_dim1 * (*k); ++idx) {
        a[idx] = (doublereal)(idx % 100) / 100.0;
    }
    for (integer idx = 0; idx < b_dim1 * N; ++idx) {
        b[idx] = (doublereal)(idx % 100) / 100.0;
    }
    for (integer idx = 0; idx < c_dim1 * N; ++idx) {
        c__[idx] = (doublereal)(idx % 100) / 100.0;
    }

    i__2 = *m;
    i__3 = *k;
    temp = 0.0;
}