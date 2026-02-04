#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef struct {
    real r;
    real i;
} singlecomplex;
typedef int integer;

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

static real beta_val = 1.5f;
static integer array_size = 8192;
static integer max_j = 2048;

void init_vars() {
    beta = &beta_val;
    c_dim1 = array_size;
    i__1 = max_j;

    c__ = (singlecomplex*)calloc(array_size * array_size, sizeof(singlecomplex));
    if (!c__) {
        exit(1);
    }

    for (int idx = 0; idx < array_size * array_size; ++idx) {
        c__[idx].r = (real)(idx % 127) / 127.0f;
        c__[idx].i = (real)((idx + 10) % 127) / 127.0f;
    }
}