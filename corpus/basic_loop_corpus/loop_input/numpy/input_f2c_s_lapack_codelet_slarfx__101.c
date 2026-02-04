#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef float real;
typedef int integer;

real *c__;
integer c_dim1;
integer i__1;
integer j;
real t1;
real t2;
real t3;
real t4;
real v1;
real v2;
real v3;
real v4;
real sum;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t total_elements = (data_size_mb * (1 << 20)) / sizeof(real);
    
    c_dim1 = 4;
    i__1 = (integer)(total_elements / c_dim1);
    
    c__ = (real*)aligned_alloc(32, (size_t)i__1 * c_dim1 * sizeof(real));
    
    t1 = 0.1f;
    t2 = 0.2f;
    t3 = 0.3f;
    t4 = 0.4f;
    v1 = 1.0f;
    v2 = 1.5f;
    v3 = 2.0f;
    v4 = 2.5f;
    sum = 0.0f;
    
    for (integer idx = 0; idx < i__1 * c_dim1; ++idx) {
        c__[idx] = (real)(idx % 100) * 0.01f;
    }
}