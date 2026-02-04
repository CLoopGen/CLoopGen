#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *n;
real *a;
integer *ipiv;
integer *incx;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer k;
integer i1;
integer n32;
integer ip;
integer ix;
real temp;

static integer _n_storage = 1024;
static real* _a_storage = NULL;
static integer* _ipiv_storage = NULL;
static integer _incx_storage = 1;

void init_vars() {
    n = &_n_storage;
    incx = &_incx_storage;
    a_dim1 = 1024;
    i1 = 1;
    n32 = 1;
    i__3 = -1;
    i__ = i1;
    i__1 = 512;
    ix = 0;

    _a_storage = (real*)calloc(a_dim1 * (*n), sizeof(real));
    if (!_a_storage) exit(1);
    a = _a_storage;

    _ipiv_storage = (integer*)malloc((*n) * sizeof(integer));
    if (!_ipiv_storage) exit(1);
    ipiv = _ipiv_storage;

    for (int i = 0; i < *n; ++i) {
        ipiv[i] = rand() % (*n);
    }

    for (int i = 0; i < a_dim1 * (*n); ++i) {
        _a_storage[i] = (real)(rand()) / RAND_MAX;
    }
}