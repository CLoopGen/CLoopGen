#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef float real;
typedef int integer;

real *c__;
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
    const size_t total_elements = (data_size_mb * 1024 * 1024) / sizeof(real);
    
    c_dim1 = 4;
    i__1 = (integer)(total_elements / c_dim1);
    
    c__ = (real*)aligned_alloc(32, i__1 * c_dim1 * sizeof(real));
    
    for (integer idx = 0; idx < i__1 * c_dim1; ++idx) {
        c__[idx] = (real)(idx % 127) * 0.01f;
    }
    
    v1 = 0.5f;
    v2 = 0.3f;
    v3 = 0.2f;
    t1 = 0.1f;
    t2 = 0.15f;
    t3 = 0.25f;
    sum = 0.0f;
    j = 0;
}