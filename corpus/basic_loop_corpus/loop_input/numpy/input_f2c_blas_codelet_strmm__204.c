#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;
typedef int logical;

integer *m;
real *alpha;
real *a;
real *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer k;
real temp;
logical nounit;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime on modern CPU
    // Empirical tuning: use matrix sizes around 1000-2000 elements per dim
    // Based on loop structure, we have two matrices: a (m x m) and b (m x i__1)
    // We choose m = 1500, i__1 = 500 to get significant computation without excessive memory

    const integer M_SIZE = 1500;
    const integer N_SIZE = 500;  // j-loop bound

    // Allocate memory for scalar pointers
    m = (integer*)malloc(sizeof(integer));
    alpha = (real*)malloc(sizeof(real));
    a = (real*)malloc(M_SIZE * M_SIZE * sizeof(real));
    b = (real*)malloc(M_SIZE * N_SIZE * sizeof(real));

    // Initialize scalar values
    *m = M_SIZE;
    *alpha = 1.5f;
    a_dim1 = M_SIZE;  // leading dimension of a
    b_dim1 = M_SIZE;  // leading dimension of b
    i__1 = N_SIZE;    // upper bound for j
    nounit = 1;       // true: diagonal is not assumed unit

    // Initialize arrays to prevent NaN or extreme values causing issues
    for (integer idx = 0; idx < M_SIZE * M_SIZE; ++idx) {
        a[idx] = (real)(idx % 100) * 0.01f;
    }
    for (integer idx = 0; idx < M_SIZE * N_SIZE; ++idx) {
        b[idx] = (real)((idx / M_SIZE) % 2) * 0.1f;  // sparse-like pattern
    }

    // Ensure at least some b[k + j*b_dim1] != 0 to trigger inner logic
    for (j = 1; j <= i__1; ++j) {
        for (k = 1; k <= *m; ++k) {
            if ((k % 7) == 0) {  // every 7th element
                b[k - 1 + j * b_dim1] = 0.5f;  // Fortran indexing: base 1 -> C base 0
            }
        }
    }

    // Initialize loop temporaries to safe values
    i__2 = *m;
    i__3 = *m - 1;
    i__ = 1;
    temp = 0.0f;
}