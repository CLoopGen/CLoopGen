#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *m;
integer *k;
real *alpha;
real *a;
real *b;
real *beta;
real *c__;
integer a_dim1;
integer b_dim1;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer l;
real temp;

void init_vars() {
    const integer size_m = 512;
    const integer size_k = 512;
    const integer size_n = 512;

    m = (integer*)malloc(sizeof(integer));
    k = (integer*)malloc(sizeof(integer));
    alpha = (real*)malloc(sizeof(real));
    beta = (real*)malloc(sizeof(real));

    *m = size_m;
    *k = size_k;
    *alpha = 1.5f;
    *beta = 1.0f;

    i__1 = size_n;
    a_dim1 = size_m;
    b_dim1 = size_k;
    c_dim1 = size_m;

    a = (real*)calloc((size_t)(a_dim1 * (*k)), sizeof(real));
    b = (real*)calloc((size_t)((*k) * size_n), sizeof(real));
    c__ = (real*)calloc((size_t)(c_dim1 * size_n), sizeof(real));

    for (integer idx = 0; idx < (*k) * size_n; ++idx) {
        b[idx] = (real)(idx % 7 + 1) / 7.0f;
    }
    for (integer idx = 0; idx < a_dim1 * (*k); ++idx) {
        a[idx] = (real)(idx % 13 + 1) / 13.0f;
    }
    for (integer idx = 0; idx < c_dim1 * size_n; ++idx) {
        c__[idx] = (real)(idx % 3 + 1) / 3.0f;
    }

    i__ = 0;
    j = 0;
    l = 0;
    temp = 0.0f;
}