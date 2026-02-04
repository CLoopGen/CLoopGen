#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *m;
real *a;
real *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    // Set matrix dimensions to achieve ~100ms runtime
    // Empirical testing shows that a 4096x4096 matrix gives suitable workload
    const int dim = 4096;
    
    // Allocate matrices with leading dimension padding
    a_dim1 = dim;
    b_dim1 = dim;
    
    // Total elements for 2D arrays accessed as [i + j * dim]
    size_t num_elements = (size_t)dim * dim;
    
    // Allocate and initialize input/output arrays
    a = (real*)calloc(num_elements, sizeof(real));
    b = (real*)calloc(num_elements, sizeof(real));
    
    // Initialize m to point to the maximum row index to process
    m = (integer*)malloc(sizeof(integer));
    *m = dim;
    
    // Set loop bound i__1 to cover all columns
    i__1 = dim;
    
    // Initialize loop indices
    i__ = 1;
    j = 1;
    
    // Fill input array with non-zero test data
    for (size_t idx = 0; idx < num_elements; ++idx) {
        a[idx] = (real)(idx % 1000) / 100.0f;
    }
}