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

static real alpha_storage;
static integer m_storage;
static real *a_storage;
static real *b_storage;

void init_vars() {
    // Set problem size to achieve roughly 0.01 seconds runtime
    // Based on typical performance, use matrix sizes around 500-1000 elements
    const int n = 800;   // Size for a and b square dimensions
    const int num_cols_b = 600;  // Number of columns in b

    // Allocate matrices
    a_storage = (real*)calloc(n * n, sizeof(real));
    b_storage = (real*)calloc(n * num_cols_b, sizeof(real));

    // Initialize non-zero values to avoid division by zero and ensure computation
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= j) {
                a_storage[i + j * n] = 1.0f + 0.01f * (i - j);  // Lower triangular with positive diagonal
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < num_cols_b; ++j) {
            b_storage[i + j * n] = 0.1f * ((i + j) % 7 + 1);
        }
    }

    // Initialize scalar parameters
    m_storage = n;
    alpha_storage = 1.5f;

    // Point external pointers to storage
    m = &m_storage;
    alpha = &alpha_storage;
    a = a_storage;
    b = b_storage;
    a_dim1 = n;
    b_dim1 = n;
    i__1 = num_cols_b;  // j loop bound: number of columns in b
    nounit = 1;  // true: meaning diagonal scaling is applied
}