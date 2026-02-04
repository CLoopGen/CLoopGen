#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef float real;
typedef int integer;

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
integer kx;
integer ky;
real temp1;
real temp2;

void init_vars() {
    // Set problem size parameters
    i__1 = 1024;  // Controls outer loop and matrix dimension
    a_dim1 = i__1; // Leading dimension of matrix 'a'

    // Allocate arrays with sufficient size to prevent out-of-bounds access
    x = (real*)calloc(i__1 * 2, sizeof(real));
    y = (real*)calloc(i__1 * 2, sizeof(real));
    a = (real*)calloc((i__1 + 1) * (a_dim1 + 1), sizeof(real)); // 1-based indexing

    // Allocate scalars
    alpha = (real*)malloc(sizeof(real));
    incx = (integer*)malloc(sizeof(integer));
    incy = (integer*)malloc(sizeof(integer));

    // Initialize values
    *alpha = 1.5f;
    *incx = 1;
    *incy = 1;

    // Initialize array contents
    for (int idx = 0; idx < i__1; ++idx) {
        x[idx] = (real)(idx * 0.1f);
        y[idx] = (real)((i__1 - idx) * 0.1f);
    }

    // Set up initial index pointers (1-based indexing convention)
    kx = 0;  // base index for x
    ky = 0;  // base index for y
    jx = kx;
    jy = ky;
}