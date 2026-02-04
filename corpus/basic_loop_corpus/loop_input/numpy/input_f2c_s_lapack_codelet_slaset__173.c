#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *m;
real *alpha;
real *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    // Set matrix dimensions and loop bounds
    const integer n = 8000;  // Controls size of the matrix, chosen to achieve ~0.01s runtime
    const integer local_m = n;

    // Allocate and initialize external scalar variables
    m = (integer*)malloc(sizeof(integer));
    *m = local_m;

    alpha = (real*)malloc(sizeof(real));
    *alpha = 3.14159f;

    // Allocate 2D array 'a' with dimensions [local_m][n], stored in column-major layout
    // We access a[i + j*a_dim1], so a_dim1 must be at least local_m
    a_dim1 = local_m;
    a = (real*)calloc((size_t)(a_dim1 * n), sizeof(real));

    // Set loop bound i__1 = min(n, *m) to ensure j <= n and prevent out-of-bounds access
    i__1 = (n < *m) ? n : *m;

    // Initialize loop indices
    i__ = 1;
    j = 1;
}