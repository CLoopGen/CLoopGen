#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *m;
integer *k;
real *alpha;
real *a;
real *b;
real *beta;
real *c__;
integer a_dim1;
integer b_dim1;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer l;
real temp;

void init_vars() {
    // Allocate and initialize scalar pointers
    m = (integer*)malloc(sizeof(integer));
    k = (integer*)malloc(sizeof(integer));
    alpha = (real*)malloc(sizeof(real));
    beta = (real*)malloc(sizeof(real));

    // Set matrix dimensions to achieve ~100-200ms runtime
    // The triple loop has complexity O(i__1 * m * k)
    // We choose sizes such that total operations are around 1e7 - 1e8 for 0.01s estimate
    *m = 200;
    *k = 250;
    i__1 = 200;  // j-loop bound

    a_dim1 = *m;
    b_dim1 = *k;
    c_dim1 = *m;

    // Allocate matrices with proper leading dimensions
    // a: [*k][*m] stored as column-major -> size = *k * *m
    a = (real*)malloc((*k) * (*m) * sizeof(real));
    // b: [*k][i__1] stored as column-major -> size = *k * i__1
    b = (real*)malloc((*k) * i__1 * sizeof(real));
    // c__: [*m][i__1] stored as column-major -> size = *m * i__1
    c__ = (real*)malloc((*m) * i__1 * sizeof(real));

    *alpha = 1.2f;
    *beta = 0.8f;

    // Initialize arrays with non-zero values to avoid degenerate cases
    for (int i = 0; i < (*k) * (*m); ++i) {
        a[i] = (real)(i % 100) / 100.0f;
    }
    for (int i = 0; i < (*k) * i__1; ++i) {
        b[i] = (real)(i % 100) / 100.0f;
    }
    for (int i = 0; i < (*m) * i__1; ++i) {
        c__[i] = (real)(i % 100) / 100.0f;
    }

    // Initialize loop bounds used directly in the loop
    i__2 = *m;
    i__3 = *k;

    // Initialize temp
    temp = 0.0f;
}