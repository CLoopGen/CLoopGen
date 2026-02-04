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
real t3;
real v1;
real v2;
real v3;
real sum;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t total_elements = (data_size_mb * (1 << 20)) / sizeof(real);
    
    c_dim1 = total_elements / 4;
    i__1 = c_dim1;
    
    if (c__) free(c__);
    c__ = (real*)aligned_alloc(32, sizeof(real) * (c_dim1 * 4 + 1));
    
    for (size_t i = 0; i < (size_t)(c_dim1 * 4 + 1); ++i) {
        c__[i] = (real)(i % 1000) * 0.01f;
    }
    
    t1 = 0.1f;
    t2 = 0.2f;
    t3 = 0.3f;
    v1 = 1.5f;
    v2 = 2.5f;
    v3 = 3.5f;
    sum = 0.0f;
    j = 0;
}