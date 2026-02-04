#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *n;
real *alpha;
real *a;
real *x;
integer *incx;
real *y;
integer *incy;
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

static integer n_storage;
static real alpha_storage;
static real *a_storage;
static real *x_storage;
static integer incx_storage;
static real *y_storage;
static integer incy_storage;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // Based on empirical tuning, n around 2000-4000 gives reasonable time for this nested loop
    n_storage = 3000;
    a_dim1 = n_storage;

    // Initialize scalar parameters
    alpha_storage = 1.5f;
    incx_storage = 1;
    incy_storage = 1;

    // Allocate arrays
    x_storage = (real*)calloc(n_storage, sizeof(real));
    y_storage = (real*)calloc(n_storage, sizeof(real));
    a_storage = (real*)calloc(n_storage * n_storage, sizeof(real));

    if (!x_storage || !y_storage || !a_storage) {
        exit(1);
    }

    // Initialize data
    for (integer i = 0; i < n_storage; ++i) {
        x_storage[i] = (real)(i + 1) * 0.5f;
        y_storage[i] = (real)(i % 7) * 0.1f;
        for (integer j = 0; j < n_storage; ++j) {
            a_storage[i + j * a_dim1] = (real)((i + j) % 13) * 0.01f;
        }
    }

    // Set external pointers
    n = &n_storage;
    alpha = &alpha_storage;
    a = a_storage;
    x = x_storage;
    incx = &incx_storage;
    y = y_storage;
    incy = &incy_storage;

    // Set loop bounds and indices
    i__1 = n_storage;  // outer loop: j from 1 to n
    jx = 0;            // base index for x (0-based in C, assuming Fortran-style 1-based logic adjusted)
    jy = 0;            // base index for y

    // Initialize temporaries
    temp1 = 0.0f;
    temp2 = 0.0f;
}