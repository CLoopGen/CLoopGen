#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *n;
real *beta;
singlecomplex *c__;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
real r__1;
singlecomplex q__1;
integer i__;
integer j;

static integer n_storage;
static real beta_storage;
static singlecomplex *c_storage;
static integer max_dim1;
static integer max_j;

void init_vars() {
    n = &n_storage;
    beta = &beta_storage;
    c_dim1 = 512;
    max_j = 512;
    *n = 1024;
    *beta = 1.5f;
    c_dim1 = *n;
    i__1 = max_j;
    max_dim1 = c_dim1;
    size_t c_size = (max_dim1 + 1) * (*n + 1);
    c_storage = (singlecomplex*)calloc(c_size, sizeof(singlecomplex));
    if (!c_storage) {
        exit(1);
    }
    c__ = c_storage;

    for (size_t idx = 0; idx < c_size; ++idx) {
        c_storage[idx].r = (real)(idx % 17);
        c_storage[idx].i = (real)(idx % 13);
    }
}