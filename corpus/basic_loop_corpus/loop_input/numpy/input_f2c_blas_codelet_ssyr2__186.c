#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *n;
real *alpha;
real *x;
integer *incx;
real *y;
integer *incy;
real *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer ix;
integer iy;
integer jx;
integer jy;
real temp1;
real temp2;

void init_vars() {
    // Set problem size for ~0.01s runtime: aim for moderate matrix/vector sizes
    const int N = 2048;  // Size of vectors and dimension of matrix
    const int INCX = 1;
    const int INCY = 1;

    // Allocate memory
    x = (real*)calloc(N * abs(INCX), sizeof(real));
    y = (real*)calloc(N * abs(INCY), sizeof(real));
    a = (real*)calloc(N * N, sizeof(real));

    // Initialize scalar parameters
    n = (integer*)malloc(sizeof(integer));
    alpha = (real*)malloc(sizeof(real));
    incx = (integer*)malloc(sizeof(integer));
    incy = (integer*)malloc(sizeof(integer));

    *n = N;
    *alpha = 1.5f;
    *incx = INCX;
    *incy = INCY;
    a_dim1 = N;  // leading dimension of 2D array 'a'

    // Set loop bounds
    i__1 = N;  // j goes from 1 to N

    // Initialize vectors with non-zero values at some positions to trigger the condition
    for (int idx = 0; idx < N; ++idx) {
        if (idx % 7 == 0) x[idx * (*incx)] = sinf(idx * 0.1f);
        if (idx % 11 == 0) y[idx * (*incy)] = cosf(idx * 0.1f);
    }

    // Initialize matrix a with small values to avoid overflow during update
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            a[i + j * a_dim1] = 0.01f * (i % 10 + j % 10);

    // Initialize indexing variables used in loop
    jx = 0;
    jy = 0;
    ix = 0;
    iy = 0;
    i__ = 1;
    temp1 = 0.0f;
    temp2 = 0.0f;
}