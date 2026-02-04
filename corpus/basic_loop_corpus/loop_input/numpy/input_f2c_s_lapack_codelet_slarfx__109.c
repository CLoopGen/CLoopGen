#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *c__ = NULL;
integer c_dim1;
integer i__1;
integer j;
real t1;
real t2;
real v1;
real v2;
real sum;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t total_elements = (data_size_mb * (1 << 20)) / sizeof(real);
    
    c_dim1 = total_elements / 3;
    i__1 = c_dim1 - 1;
    
    if (c__) free(c__);
    c__ = (real*)aligned_alloc(32, total_elements * sizeof(real));
    
    for (size_t i = 0; i < total_elements; ++i) {
        c__[i] = (real)(i % 1000) / 100.0f;
    }
    
    t1 = 0.5f;
    t2 = 0.25f;
    v1 = 1.7f;
    v2 = 0.8f;
    sum = 0.0f;
    j = 0;
}