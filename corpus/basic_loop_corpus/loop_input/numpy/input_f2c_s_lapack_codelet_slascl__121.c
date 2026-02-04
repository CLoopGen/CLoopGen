#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *m;
real *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
real mul;

static real *a_data = NULL;
static integer m_value;

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime
    // Empirical tuning: use a matrix of size ~4096 x 4096 elements (about 67M elements, ~268MB for floats)
    // But reduce slightly to stay within 1MB-256MB as requested.
    // Use 8192x3276 -> approx 268 million elements? Too big.

    // Let's aim for about 16 million elements maximum (64 MB), so we pick:
    // m = 4096, i__1 = 4096 -> inner loop triangular work ~ (4096^2)/2 ~ 8M iterations
    // Each iteration accesses one float -> total memory touched ~32 MB

    m_value = 4096;
    *m = m_value;
    i__1 = 4096;  // j from 1 to 4096
    a_dim1 = 4096; // leading dimension
    mul = 2.0f;

    // Allocate a as a 2D array in column-major layout: [1:m][1:i__1] -> [1:4096][1:4096]
    // We use 1-based indexing as implied by loop starting at 1
    a_data = (real*)calloc((m_value + 1) * (i__1 + 1), sizeof(real));
    if (!a_data) {
        exit(1);
    }

    // Set pointer a to base of data, such that a[i + j*a_dim1] maps correctly
    // Since we want indices starting at 1, we point 'a' to the beginning of allocated block
    // and access [i][j] as a[i + j*a_dim1] with i,j >=1
    a = a_data;
}

// Provide definitions for all externs
integer *m = &m_value;