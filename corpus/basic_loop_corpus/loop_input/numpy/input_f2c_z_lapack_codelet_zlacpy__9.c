#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *m;
doublecomplex *a;
doublecomplex *b;
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

    a = (doublecomplex*)calloc((size_t)(a_dim1 + 1) * (size_n + 1), sizeof(doublecomplex));
    b = (doublecomplex*)calloc((size_t)(b_dim1 + 1) * (size_n + 1), sizeof(doublecomplex));

    for (integer idx = 1; idx <= size_m; ++idx) {
        for (integer jdx = 1; jdx <= size_n; ++jdx) {
            integer pos = idx + jdx * a_dim1;
            a[pos].r = sin(idx);
            a[pos].i = cos(jdx);
        }
    }

    i__ = 1;
    j = 1;
    i__2 = *m;
    i__3 = 1;
    i__4 = 1;
}