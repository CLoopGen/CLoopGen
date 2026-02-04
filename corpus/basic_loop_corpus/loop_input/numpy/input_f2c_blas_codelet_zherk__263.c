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

integer *n;
doublecomplex *c__;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    const integer size = 5000;
    n = (integer*)malloc(sizeof(integer));
    *n = size;
    c_dim1 = size;
    i__1 = size;

    c__ = (doublecomplex*)calloc((size_t)(size + 1) * (size + 1), sizeof(doublecomplex));
}

// End of file