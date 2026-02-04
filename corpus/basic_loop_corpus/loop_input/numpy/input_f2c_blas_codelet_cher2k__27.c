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
    // The loop runs approximately (i__1 * (average of inner loop iterations)) times
    // Inner loop: for j=1 to i__1, and for i_=j to n, so total iterations ≈ i__1 * (n - i__1/2)
    // We want this in the range of 10-100 million for ~0.01s on modern CPU

    // Let's set n = 4096, i__1 = 4096 -> total iterations ≈ sum_{j=1}^{4096} (4096 - j + 1) = (4096)(4097)/2 ≈ 8.4e6
    // This is safe and should run in about 0.01s

    const integer dim = 4096;
    *n = dim;
    i__1 = dim;
    c_dim1 = dim;  // leading dimension of matrix c__

    // Allocate 2D array as column-major: c__[1..n][1..i__1] => we need up to index n + i__1*c_dim1
    // Using 1-based indexing: maximum index is n + i__1 * c_dim1
    size_t alloc_size = (dim + 1) * (dim + 1);  // +1 for 1-based indexing safety
    c__ = (singlecomplex*)calloc(alloc_size, sizeof(singlecomplex));
    if (!c__) exit(1);

    // Ensure all accesses are within bounds:
    // Maximum access: i__ + j * c_dim1 <= n + i__1 * c_dim1 <= dim + dim*dim = dim*(dim+1)
    // Our allocation covers [0 .. (dim+1)*(dim+1)-1], so it's safe.
}

// Define n as a pointer to an integer that will hold the value of dim
integer _n_storage;
integer *n = &_n_storage;