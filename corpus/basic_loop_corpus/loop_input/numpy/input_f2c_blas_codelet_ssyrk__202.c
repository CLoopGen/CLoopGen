#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *n;
integer *k;
real *alpha;
real *beta;
real *a;
real *c__;
integer a_dim1;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer l;
real temp;

void init_vars() {
    // Set problem size for approximately 0.01 seconds runtime
    // Based on typical performance, choose n ≈ 500-600, k ≈ 256 to get desired compute load
    const int n_val = 512;
    const int k_val = 256;

    // Initialize scalar parameters
    n = (integer*)malloc(sizeof(integer));
    k = (integer*)malloc(sizeof(integer));
    alpha = (real*)malloc(sizeof(real));
    beta = (real*)malloc(sizeof(real));
    
    *n = n_val;
    *k = k_val;
    *alpha = 1.5f;
    *beta = 0.8f;

    // Set loop bound i__1 = n for valid iteration space
    i__1 = *n;

    // Allocate matrices in column-major layout: a[k][n], c[n][n]
    a_dim1 = *k;  // leading dimension of a
    c_dim1 = *n;  // leading dimension of c

    a = (real*)calloc(a_dim1 * (*n), sizeof(real));
    c__ = (real*)calloc(c_dim1 * (*n), sizeof(real));

    // Initialize a with non-zero values to ensure computation happens
    for (int col = 0; col < *n; ++col) {
        for (int row = 0; row < *k; ++row) {
            a[row + col * a_dim1] = (real)(rand() % 100) / 100.0f;
        }
    }

    // Initialize c__ with some baseline values
    for (int col = 0; col < *n; ++col) {
        for (int row = 0; row < *n; ++row) {
            c__[row + col * c_dim1] = (real)(rand() % 50) / 100.0f;
        }
    }

    // Ensure temp is initialized
    temp = 0.0f;
}