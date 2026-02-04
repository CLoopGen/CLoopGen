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
doublereal *beta;
doublecomplex *c__;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
doublereal d__1;
doublecomplex z__1;
integer i__;
integer j;

static integer n_storage;
static doublereal beta_storage;

void init_vars() {
    n = &n_storage;
    beta = &beta_storage;
    c_dim1 = 1024;
    i__1 = 512;
    *n = 1024;
    *beta = 2.0;

    size_t array_size = (size_t)(*n) * c_dim1;
    c__ = (doublecomplex*)calloc(array_size, sizeof(doublecomplex));
    if (!c__) {
        exit(1);
    }

    for (size_t idx = 0; idx < array_size; ++idx) {
        c__[idx].r = (doublereal)(idx % 17);
        c__[idx].i = (doublereal)(idx % 13);
    }
}