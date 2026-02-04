#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;
typedef int logical;

integer *n;
real *a;
real *x;
integer *incx;
integer a_dim1;
integer i__1;
integer i__;
integer j;
integer ix;
integer jx;
integer kx;
real temp;
logical nounit;

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime
    // Empirical tuning: matrix size around 2000-3000 for reasonable timing
    const int N = 2500;

    // Allocate and initialize n
    static integer n_val = N;
    n = &n_val;

    // Allocate and initialize incx
    static integer incx_val = 1;
    incx = &incx_val;

    // Set dimension of matrix a (column-major, leading dimension)
    a_dim1 = N;

    // Allocate matrix a: size N x N
    a = (real*)aligned_alloc(32, sizeof(real) * N * N);
    
    // Allocate vector x
    x = (real*)aligned_alloc(32, sizeof(real) * N);

    // Initialize a and x with non-zero values to ensure meaningful computation
    for (int i = 0; i < N; ++i) {
        x[i] = 1.0f + (i % 7) * 0.1f;
        for (int j = 0; j < N; ++j) {
            a[i + j * a_dim1] = ((i == j) ? 1.0f : 0.5f) / (1.0f + abs(i - j));
        }
    }

    // Set nounit = true (non-unit diagonal), so diagonal scaling will occur
    nounit = 1;

    // Initialize loop indices
    jx = N - 1;  // Start from last element assuming incx=1
    kx = N - 1;
}