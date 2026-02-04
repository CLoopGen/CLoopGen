#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef float real;
typedef int integer;

real *c__ = NULL;
integer c_dim1 = 0;
integer i__1 = 0;
integer j = 0;
real t1 = 0.0f;
real t2 = 0.0f;
real t3 = 0.0f;
real t4 = 0.0f;
real t5 = 0.0f;
real v1 = 0.0f;
real v2 = 0.0f;
real v3 = 0.0f;
real v4 = 0.0f;
real v5 = 0.0f;
real sum = 0.0f;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t total_elements = (data_size_mb * (1 << 20)) / sizeof(real);
    
    c_dim1 = total_elements / 6;
    if (c_dim1 < 1000) {
        c_dim1 = 1000;
    }
    
    i__1 = c_dim1 - 1;
    
    t1 = 0.1f;
    t2 = 0.2f;
    t3 = 0.3f;
    t4 = 0.4f;
    t5 = 0.5f;
    v1 = 1.0f;
    v2 = 1.1f;
    v3 = 1.2f;
    v4 = 1.3f;
    v5 = 1.4f;
    sum = 0.0f;
    j = 0;

    if (c__ != NULL) {
        free(c__);
    }
    c__ = (real*)aligned_alloc(32, sizeof(real) * (c_dim1 * 6 + 1));
    if (c__ == NULL) {
        exit(1);
    }

    for (size_t i = 0; i < (size_t)(c_dim1 * 6 + 1); ++i) {
        c__[i] = (real)(i % 1000) * 0.01f;
    }
}