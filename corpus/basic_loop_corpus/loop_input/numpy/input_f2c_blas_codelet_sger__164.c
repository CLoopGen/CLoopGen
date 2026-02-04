#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *m;
real *alpha;
real *x;
real *y;
integer *incy;
real *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer jy;
real temp;

void init_vars() {
    // Set problem size to achieve ~0.01 sec runtime
    // Based on typical performance, use m ≈ 4096, i__1 ≈ 4096, leading to ~16M operations
    const int m_val = 4096;
    const int i__1_val = 4096;
    
    // Allocate and initialize scalar variables
    m = (integer*)malloc(sizeof(integer));
    *m = m_val;
    
    alpha = (real*)malloc(sizeof(real));
    *alpha = 1.5f;
    
    incy = (integer*)malloc(sizeof(integer));
    *incy = 1;
    
    a_dim1 = m_val;  // leading dimension of matrix a
    
    // Allocate arrays
    x = (real*)malloc(m_val * sizeof(real));
    y = (real*)malloc(i__1_val * sizeof(real));
    a = (real*)malloc(m_val * i__1_val * sizeof(real));
    
    // Initialize arrays to prevent NaN/undefined behavior
    for (i__ = 0; i__ < m_val; ++i__) {
        x[i__] = (real)(i__ % 100) * 0.01f;
    }
    
    for (j = 0; j < i__1_val; ++j) {
        y[j] = (j % 3 == 0) ? 1.0f : 0.0f;  // some zeros, some non-zeros
    }
    
    for (i__ = 0; i__ < m_val * i__1_val; ++i__) {
        a[i__] = 0.1f;
    }
    
    // Initialize loop bounds and indices
    i__1 = i__1_val;
    i__2 = *m;
    i__ = 1;
    j = 1;
    jy = 1;  // Fortran-style indexing offset by 1
    temp = 0.0f;
}