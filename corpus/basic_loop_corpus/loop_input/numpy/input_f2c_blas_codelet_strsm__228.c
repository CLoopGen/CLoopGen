#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;
typedef int logical;

integer *m;
integer *n;
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

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // Based on typical performance, use m=512, n=512, a_dim1=b_dim1=512
    const int dim = 512;
    
    // Allocate scalars
    m = (integer*)malloc(sizeof(integer));
    n = (integer*)malloc(sizeof(integer));
    alpha = (real*)malloc(sizeof(real));
    
    // Initialize scalar values
    *m = dim;
    *n = dim;
    *alpha = 1.2f;
    a_dim1 = dim;
    b_dim1 = dim;
    nounit = 1;
    temp = 0.0f;
    i__ = 0;
    j = 0;
    k = 0;
    
    // Total elements for 2D arrays: dim x dim
    const size_t total_a = dim * dim;
    const size_t total_b = dim * dim;
    
    // Allocate and initialize arrays
    a = (real*)calloc(total_a, sizeof(real));
    b = (real*)calloc(total_b, sizeof(real));
    
    // Initialize diagonal of 'a' to non-zero values to ensure division works
    for (int idx = 0; idx < dim; ++idx) {
        a[idx + idx * a_dim1] = 2.0f;  // Diagonal elements
    }
    
    // Initialize off-diagonal elements of 'a' sparsely
    for (int row = 1; row < dim; ++row) {
        for (int col = 0; col < row && col < 10; ++col) {
            a[row + col * a_dim1] = 0.1f;
        }
    }
    
    // Initialize b with non-zero values
    for (int i = 0; i < total_b; ++i) {
        b[i] = 1.0f + (i % 7);
    }
    
    // Set loop bound i__1 to min(m,n)-1 to stay in bounds
    i__1 = (*m < *n) ? *m : *n;
    if (i__1 > 0) i__1--;  // Ensure k goes up to n-1 so j=k+1 stays in range
    i__2 = 0;
    i__3 = 0;
}