#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *m;
doublereal *alpha;
doublereal *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    // Set problem size to ensure ~0.01 seconds runtime
    // The loop writes to approximately (j-1) elements per column j, up to min(j-1, *m)
    // Total operations ≈ sum_{j=2}^{i__1} min(j-1, *m)
    // We choose *m and i__1 such that total memory accessed is ~100MB for good cache behavior and timing

    const integer n = 10000;  // columns
    const integer m_val = 8000;  // rows, also value for *m
    const integer total_size = n * m_val;

    // Allocate and initialize scalar variables
    m = (integer*)malloc(sizeof(integer));
    *m = m_val;

    alpha = (doublereal*)malloc(sizeof(doublereal));
    *alpha = 3.14159;

    a = (doublereal*)calloc(total_size, sizeof(doublereal));
    a_dim1 = m_val;  // leading dimension

    i__1 = n;  // outer loop bound
    i__2 = 0;
    i__3 = 0;
    i__ = 1;
    j = 2;

    // Ensure all array accesses in the loop are within [1, m_val] x [1, n] (1-indexed)
    // In the loop: a[i__ + j * a_dim1], with i__ from 1 to min(j-1, *m), j from 2 to i__1
    // Max index: i__ = *m (<= m_val), j = i__1 (<= n) => index = m_val + n * m_val = m_val*(n+1)
    // But we allocated m_val * n, so we must use 1-based indexing safely into a matrix of size m_val x n
    // Our allocation supports linear indices up to m_val*n - 1 (0-based), so we need to ensure:
    //   i__ + j * a_dim1 - 1 < m_val * n   (converting 1-based to 0-based)
    // Max: m_val + n * m_val - 1 = m_val*(n+1)-1 -> too big!
    // So we must adjust: allocate extra row or reduce bounds.

    // Instead, re-allocate with safe dimensions: (m_val+1) * (n+1) to allow 1-based indexing up to [m_val][n]
    free(a);
    a = (doublereal*)calloc((size_t)(m_val + 1) * (n + 1), sizeof(doublereal));
    a_dim1 = m_val + 1;

    // Keep same logical values
    *m = m_val;
    i__1 = n;
}