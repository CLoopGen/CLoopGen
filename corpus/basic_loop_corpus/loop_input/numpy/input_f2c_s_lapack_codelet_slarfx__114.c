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
real t4;
real t5;
real t6;
real t7;
real v1;
real v2;
real v3;
real v4;
real v5;
real v6;
real v7;
real sum;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t total_elements = (data_size_mb * 1024 * 1024) / sizeof(real);
    
    c__ = (real*)aligned_alloc(32, total_elements * sizeof(real));
    if (!c__) exit(1);

    c_dim1 = 1000;
    i__1 = c_dim1 - 7;

    t1 = 0.1f; t2 = 0.2f; t3 = 0.3f; t4 = 0.4f;
    t5 = 0.5f; t6 = 0.6f; t7 = 0.7f;
    v1 = 1.0f; v2 = 1.1f; v3 = 1.2f; v4 = 1.3f;
    v5 = 1.4f; v6 = 1.5f; v7 = 1.6f;
    sum = 0.0f;

    for (size_t i = 0; i < total_elements; ++i) {
        c__[i] = (real)(i % 1000) * 0.01f;
    }
}