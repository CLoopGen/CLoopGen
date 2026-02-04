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

integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

doublecomplex *a;

void init_vars() {
    i__1 = 5000;
    a_dim1 = i__1;

    size_t size = (size_t)(a_dim1 + 1) * (i__1 + 1);
    a = (doublecomplex*)calloc(size, sizeof(doublecomplex));
    if (!a) {
        exit(1);
    }

    for (size_t idx = 0; idx < size; ++idx) {
        a[idx].r = 1.0;
        a[idx].i = 0.5;
    }
}