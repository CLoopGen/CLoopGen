#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *n;
real *beta;
real *c__;
integer c_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    // Allocate and initialize scalar variables
    n = (integer*)malloc(sizeof(integer));
    beta = (real*)malloc(sizeof(real));
    *n = 2048;  // Set matrix size to ~2K x 2K to get ~16MB of data (2048*2048*sizeof(float))
    *beta = 1.5f;
    c_dim1 = *n;  // leading dimension same as n

    // Allocate 2D array c__[i + j*c_dim1], size n x n
    c__ = (real*)calloc((*n) * (*n), sizeof(real));

    // Initialize loop bounds
    i__1 = *n;  // j runs from 1 to n
    i__2 = *n;  // inner loop bound set to n

    // Ensure all indices are in bounds: j from 1 to i__1, i__ from j to i__2
    // With c__[i__ + j * c_dim1], max index is i__2 + i__1 * c_dim1 <= n + n*n = n*(n+1)
    // But we allocated n*n, so we must ensure i__ and j are 1-based and within [1,n]
    // Our allocation covers indices [0, n*n), and we access [1 + 1*c_dim1] up to [n + n*c_dim1]
    // Since c_dim1 = n, the index i__ + j*c_dim1 goes from 1+1*n to n+n*n.
    // So maximum index is n + n*n = n*(n+1), which exceeds n*n by n.
    // Therefore, we must adjust allocation to cover up to index n*(n+1), or use 1-based indexing safely.

    // Instead, we reallocate with extra padding for 1-based indexing: we need index up to n + n*n
    free(c__);
    c__ = (real*)calloc((*n + 1) * (*n + 1), sizeof(real));  // Allocate (n+1)x(n+1) to safely allow 1-based indexing

    // Reset bounds
    i__1 = *n;
    i__2 = *n;
}