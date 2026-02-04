#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *alpha;
doublereal *x;
integer *incx;
doublereal *y;
integer *incy;
doublereal *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer ix;
integer iy;
integer jx;
integer jy;
integer kx;
integer ky;
doublereal temp1;
doublereal temp2;

void init_vars() {
    // Problem size settings
    const int n = 4096;  // Controls matrix and vector sizes
    const int inc = 1;   // stride increment

    // Allocate alpha (scalar)
    alpha = (doublereal*)malloc(sizeof(doublereal));
    *alpha = 1.5;

    // Allocate vectors x and y of length n
    x = (doublereal*)calloc(n, sizeof(doublereal));
    y = (doublereal*)calloc(n, sizeof(doublereal));

    // Initialize non-zero values in the middle to trigger condition
    x[n/2] = 1.0;
    y[n/2] = 1.0;

    incx = (integer*)malloc(sizeof(integer));
    *incx = inc;

    incy = (integer*)malloc(sizeof(integer));
    *incy = inc;

    // Allocate symmetric matrix a: n x n
    a_dim1 = n;
    a = (doublereal*)calloc((size_t)n * n, sizeof(doublereal));

    // Set loop bounds
    i__1 = n;  // outer loop: j from 1 to n

    // Initialize starting indices (Fortran-style 1-based indexing)
    kx = 1;
    ky = 1;
    jx = 1;
    jy = 1;

    // Ensure no out-of-bounds access:
    // Inner loop: i__ from 1 to j, with ix = kx + (i__-1)*incx
    // So maximum index into x[] is roughly kx + (n-1)*incx <= n
    // With kx=1, incx=1 -> max index = n, so we need x[1..n] valid (we have 0..n-1)
    // Therefore, we use 1-based indexing on 0-indexed arrays: access x[ix-1]

    // No initialization needed for temp1, temp2, i__, j, etc. — they are overwritten in loop

    // Warm up or adjust problem size to take ~0.01s
    // For n=4096, total operations ~ O(n^3) in worst case but early exit on zero
    // With sparse non-zero at center, inner loop runs fully only once
    // Peak computation: one j near n/2, inner loop up to ~n/2, so ~ sum_{j=1}^{n/2} j ~ O(n^2/4)
    // Which for n=4096 gives ~8e6 iterations, which is acceptable and likely within 0.01s range
}