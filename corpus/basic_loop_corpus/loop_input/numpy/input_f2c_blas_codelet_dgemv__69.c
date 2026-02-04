#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *m;
doublereal *alpha;
doublereal *a;
doublereal *x;
integer *incx;
doublereal *y;
integer *incy;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer iy;
integer jx;
integer ky;
doublereal temp;

void init_vars() {
    // Problem dimensions
    const integer M = 4096;   // rows of matrix 'a'
    const integer N = 4096;   // cols of matrix 'a', also controls i__1 (loop bound)
    
    // Set *m = M, i__1 = N to control loop bounds
    m = (integer*)malloc(sizeof(integer));
    *m = M;

    // Allocate and initialize alpha
    alpha = (doublereal*)malloc(sizeof(doublereal));
    *alpha = 1.5;

    // Allocate matrix a[M][N], column-major storage (Fortran-style)
    a_dim1 = M; // leading dimension
    a = (doublereal*)calloc(M * N, sizeof(doublereal));
    for (integer idx = 0; idx < M * N; ++idx) {
        a[idx] = (doublereal)(idx % 127) / 127.0;
    }

    // Vector x with length N
    x = (doublereal*)calloc(N, sizeof(doublereal));
    incx = (integer*)malloc(sizeof(integer));
    *incx = 1;
    for (integer i = 0; i < N; ++i) {
        x[i] = (i % 2) ? 1.0 : 0.0;  // some non-zero pattern
    }

    // Vector y with length M
    y = (doublereal*)calloc(M, sizeof(doublereal));
    incy = (integer*)malloc(sizeof(integer));
    *incy = 1;
    for (integer i = 0; i < M; ++i) {
        y[i] = (doublereal)i / M;
    }

    // Loop control variables
    i__1 = N;  // outer loop bound

    // Initial indexing offsets
    jx = 0;    // starting index for x
    ky = 0;    // base offset for y
}