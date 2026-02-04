#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *m;
singlecomplex *a;
singlecomplex *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__;
integer j;

void init_vars() {
    const integer size_m = 4096;
    const integer size_n = 4096;

    m = (integer*)malloc(sizeof(integer));
    *m = size_m;

    a_dim1 = size_m;
    b_dim1 = size_m;
    i__1 = size_n;

    a = (singlecomplex*)calloc((size_t)(a_dim1 * i__1), sizeof(singlecomplex));
    b = (singlecomplex*)calloc((size_t)(b_dim1 * i__1), sizeof(singlecomplex));

    for (integer idx = 0; idx < a_dim1 * i__1; ++idx) {
        a[idx].r = (real)(idx % 100) / 10.0f;
        a[idx].i = (real)((idx + 10) % 100) / 10.0f;
    }

    i__ = 0;
    j = 0;
    i__2 = 0;
    i__3 = 0;
    i__4 = 0;
}