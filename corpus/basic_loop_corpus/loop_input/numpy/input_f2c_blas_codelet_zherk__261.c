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

integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

doublecomplex *c__;

void init_vars() {
    i__1 = 5000;
    c_dim1 = i__1 + 1;
    size_t c_size = ((size_t)(i__1) + 1) * ((size_t)c_dim1 + 1);
    c__ = (doublecomplex *)calloc(c_size, sizeof(doublecomplex));
    if (!c__) exit(1);
}