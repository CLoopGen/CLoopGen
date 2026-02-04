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
    const integer total_elements = 8000000; // ~128 MB of data (each complex is 16 bytes)
    const integer rows = 4000;
    const integer cols = 2000;

    m = (integer*)malloc(sizeof(integer));
    *m = rows;

    a_dim1 = rows;
    b_dim1 = rows;
    i__1 = cols;

    a = (doublecomplex*)calloc(total_elements, sizeof(doublecomplex));
    b = (doublecomplex*)calloc(total_elements, sizeof(doublecomplex));

    for (integer idx = 0; idx < total_elements; ++idx) {
        a[idx].r = (doublereal)(idx % 100);
        a[idx].i = (doublereal)((idx + 10) % 100);
    }
}