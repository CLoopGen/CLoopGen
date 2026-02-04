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

doublecomplex *c__ = NULL;
integer c_dim1 = 0;
integer i__1 = 0;
integer i__2 = 0;
integer i__3 = 0;
integer i__ = 0;
integer j = 0;

void init_vars() {
    c_dim1 = 1024;
    i__1 = 512;

    size_t array_size = (c_dim1 + 1) * (i__1 + 1);
    c__ = (doublecomplex*)calloc(array_size, sizeof(doublecomplex));
    if (!c__) {
        exit(1);
    }
}