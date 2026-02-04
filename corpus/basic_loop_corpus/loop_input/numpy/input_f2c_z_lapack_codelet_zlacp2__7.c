#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *m;
doublereal *a;
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

    a = (doublereal*)calloc((size_m * size_n), sizeof(doublereal));
    b = (doublecomplex*)calloc((size_m * size_n), sizeof(doublecomplex));

    for (integer idx = 0; idx < size_m * size_n; ++idx) {
        a[idx] = (doublereal)(idx % 100);
    }
}