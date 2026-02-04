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
singlecomplex *c__;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime
    // The loop runs approximately i__1 * (*n - j + 1) iterations, worst case when j=1: i__1 * *n
    // We aim for about 10^7 operations (modern CPU: ~1e9 ops/sec -> 0.01 sec for 10^7)
    // Let's set *n = 4096, i__1 = 4096 => total ~ (4096 * 4096 / 2) ~ 8e6 complex assignments

    *n = 4096;
    i__1 = 4096;

    c_dim1 = *n;  // leading dimension of the matrix c__

    // Allocate 2D array as column-major matrix of size n x n (Fortran-style)
    c__ = (singlecomplex*)calloc((size_t)(*n) * (size_t)c_dim1, sizeof(singlecomplex));
    if (!c__) {
        exit(1);
    }

    // Ensure other variables are initialized to safe values (will be overwritten in loop)
    i__2 = *n;
    i__3 = 0;
    i__ = 1;
    j = 1;
}

// Allocate global pointers
integer n_storage = 0;
singlecomplex* c__storage = NULL;

static void __attribute__((constructor)) initialize() {
    n = &n_storage;
    c__ = NULL;
    init_vars();
}