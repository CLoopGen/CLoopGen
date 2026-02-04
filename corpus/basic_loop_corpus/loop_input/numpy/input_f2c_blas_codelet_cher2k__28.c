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
static singlecomplex* c_storage = NULL;

void init_vars() {
    n = &n_storage;
    beta = &beta_storage;
    n_storage = 4096;
    c_dim1 = n_storage;
    i__1 = n_storage;
    beta_storage = 1.5f;

    size_t total_size = (n_storage + 1) * (n_storage + 1) * sizeof(singlecomplex);
    c_storage = (singlecomplex*)calloc(n_storage + 1, (n_storage + 1) * sizeof(singlecomplex));
    if (!c_storage) {
        exit(1);
    }
    c__ = c_storage;
}