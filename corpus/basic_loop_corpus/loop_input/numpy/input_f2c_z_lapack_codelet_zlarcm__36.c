#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *m;
doublecomplex *b;
doublereal *rwork;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; // Aim for ~64 MB of data
    const integer n = 4096; // Number of columns
    const integer m_val = target_bytes / (n * sizeof(doublereal)) + 1; // Adjust rows to fit size

    // Allocate and assign m
    m = (integer*)malloc(sizeof(integer));
    *m = m_val;

    b_dim1 = m_val; // Leading dimension of b
    i__1 = n;       // Outer loop bound (columns)

    // Allocate b: assumed to be a 2D array of size m x n, column-major
    b = (doublecomplex*)calloc((size_t)(b_dim1 * n + 1), sizeof(doublecomplex));

    // Allocate rwork: size m * n
    rwork = (doublereal*)calloc((size_t)(*m * n), sizeof(doublereal));

    // Ensure no out-of-bounds access:
    // Max index into b: i__ + j*b_dim1 <= m_val + n*b_dim1 <= m_val + n*m_val = m_val*(n+1)
    // Our allocation is b_dim1 * n + 1 = m_val * n + 1, so we need m_val*(n+1) <= m_val*n + 1?
    // That would fail. So instead ensure j <= n and i__ <= m_val -> max index = m_val + n*b_dim1 = m_val*(n+1)
    // We must reallocate b safely.

    free(b);
    // Allocate b with extra padding for safe indexing up to i__ + j*b_dim1 where i__ <= m_val, j <= n
    // Max index: m_val + n * b_dim1 = m_val + n * m_val = m_val*(n+1)
    b = (doublecomplex*)calloc((size_t)(m_val * (n + 1) + 1), sizeof(doublecomplex));

    // Initialize some values in b to avoid undefined behavior when reading .r
    for (integer col = 1; col <= n; ++col) {
        for (integer row = 1; row <= m_val; ++row) {
            integer idx = row + col * b_dim1;
            b[idx].r = (doublereal)(row * 0.01);
            b[idx].i = (doublereal)(col * 0.01);
        }
    }

    // Initialize loop temp variables to zero (they are modified in loop anyway)
    i__2 = 0;
    i__3 = 0;
}