#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

integer h_dim1;
integer i__1;
integer i__;

real *h__;
real *wr;
real *wi;

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime
    // Empirical testing shows that ~32M iterations is roughly 0.01s on modern CPUs
    i__1 = 32768;

    // Ensure square matrix access: h[i + i*h_dim1] => need at least i__1 * (i__1 + 1) elements?
    // Actually, we only access diagonal: h[i][i] where row-major indexing would be i + i*h_dim1
    // So we model h as a square matrix of size i__1 x i__1
    h_dim1 = i__1;

    // Allocate arrays with proper sizes
    size_t total_size = (size_t)(i__1 + 1) * (size_t)(i__1 + 1);  // 1-based indexing
    h__ = (real*)calloc(total_size, sizeof(real));
    wr = (real*)calloc(i__1 + 1, sizeof(real));
    wi = (real*)calloc(i__1 + 1, sizeof(real));

    // Initialize h__ with some data on diagonal to make it observable
    for (int i = 1; i <= i__1; ++i) {
        h__[i + i * h_dim1] = (real)(i * 0.5f);
    }
}