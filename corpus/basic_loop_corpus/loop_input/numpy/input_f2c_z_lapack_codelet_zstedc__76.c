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
doublecomplex *z__;
doublereal *rwork;
integer z_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__;
integer j;

void init_vars() {
    // Set problem size to achieve ~0.01 sec runtime
    // Empirical tuning: use about 8-16 million elements for reasonable timing
    const int N = 4096;  // Adjusted to ensure memory safety and timing

    // Allocate and initialize n
    n = (integer*)malloc(sizeof(integer));
    *n = N;

    // Set z_dim1 equal to leading dimension, typically >= *n
    z_dim1 = *n;

    // i__1 is upper bound for j: must be <= number of columns in z__
    i__1 = 64;  // Limit columns to control total work to ~0.01s

    // Total size of z__: rows = *n, cols = i__1
    z__ = (doublecomplex*)calloc((size_t)(*n) * (size_t)z_dim1, sizeof(doublecomplex));

    // rwork size: must be at least (j-1)*(*n) + i__ for max j=i__1 and i__=*n
    // so size = (i__1 - 1) * (*n) + (*n) = i__1 * (*n)
    const size_t rwork_size = (size_t)i__1 * (size_t)(*n);
    rwork = (doublereal*)malloc(rwork_size * sizeof(doublereal));

    // Initialize rwork with dummy data
    for (size_t idx = 0; idx < rwork_size; ++idx) {
        rwork[idx] = (doublereal)(idx + 1);
    }

    // Initialize loop temporaries (will be overwritten in loop, but set to safe values)
    i__2 = *n;
    i__3 = 1;
    i__4 = 1;
    i__ = 1;
    j = 1;
}