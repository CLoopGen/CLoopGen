#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

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
real t8;
real t9;
real v1;
real v2;
real v3;
real v4;
real v5;
real v6;
real v7;
real v8;
real v9;
real sum;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t total_elements = (data_size_mb * (1 << 20)) / sizeof(real);
    
    c_dim1 = 1000;
    i__1 = total_elements > c_dim1 * 10 ? c_dim1 : total_elements / 10;
    
    if (i__1 < 1) i__1 = 1;
    
    size_t required_elements = i__1 + c_dim1 * 10;
    if (required_elements > total_elements) {
        required_elements = total_elements;
        i__1 = required_elements - c_dim1 * 10;
        if (i__1 < 1) {
            i__1 = 1;
            c_dim1 = (required_elements - 10) / 10;
            if (c_dim1 < 1) c_dim1 = 1;
        }
    }

    c__ = (real*)aligned_alloc(32, required_elements * sizeof(real));
    if (!c__) exit(1);

    for (size_t i = 0; i < required_elements; ++i) {
        c__[i] = (real)(i % 1000) * 0.01f;
    }

    t1 = 0.1f; t2 = 0.2f; t3 = 0.3f; t4 = 0.4f; t5 = 0.5f;
    t6 = 0.6f; t7 = 0.7f; t8 = 0.8f; t9 = 0.9f;
    v1 = 1.1f; v2 = 1.2f; v3 = 1.3f; v4 = 1.4f; v5 = 1.5f;
    v6 = 1.6f; v7 = 1.7f; v8 = 1.8f; v9 = 1.9f;
    sum = 0.0f;
    j = 0;
}