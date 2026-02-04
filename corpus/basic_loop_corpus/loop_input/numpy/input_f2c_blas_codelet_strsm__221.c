#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

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
integer i__;
integer j;
integer k;
logical nounit;

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime
    // Empirical tuning: m around 1000-2000 gives reasonable time
    int m_val = 1500;
    
    // i__1 controls outer loop (j-loop) iterations
    i__1 = 10;
    
    // Allocate and initialize scalar pointers
    m = (integer*)malloc(sizeof(integer));
    *m = m_val;
    
    alpha = (real*)malloc(sizeof(real));
    *alpha = 1.2f;  // Not 1.F to trigger the scaling branch
    
    // Set matrix dimensions
    a_dim1 = m_val;
    b_dim1 = m_val;
    
    // Allocate matrices in column-major layout (Fortran-style)
    a = (real*)calloc(m_val * m_val, sizeof(real));
    b = (real*)calloc(m_val * m_val, sizeof(real));
    
    // Initialize diagonal of A to non-zero values for division
    for (int idx = 0; idx < m_val; ++idx) {
        a[idx + idx * a_dim1] = 2.0f;
    }
    
    // Fill some off-diagonal elements
    for (int row = 0; row < m_val; ++row) {
        for (int col = 0; col < row; ++col) {
            a[row + col * a_dim1] = 0.1f * ((real)(rand() % 10));
        }
    }
    
    // Initialize b with non-zero values in lower triangle
    for (int col = 0; col < i__1; ++col) {
        for (int row = 0; row < m_val; ++row) {
            b[row + col * b_dim1] = 1.0f + 0.1f * ((real)(rand() % 20));
        }
    }
    
    // Enable nounit so division branch is taken
    nounit = 1;
    
    // Initialize loop temp variables to safe values
    i__2 = 0;
    i__ = 0;
    j = 0;
    k = 0;
}