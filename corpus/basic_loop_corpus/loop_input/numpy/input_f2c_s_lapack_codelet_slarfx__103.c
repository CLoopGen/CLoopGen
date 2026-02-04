#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
real v1;
real v2;
real v3;
real v4;
real v5;
real v6;
real sum;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t floats_per_mb = (1 << 20) / sizeof(real);
    const size_t total_elements = data_size_mb * floats_per_mb;

    c_dim1 = 7;
    i__1 = (integer)(total_elements / c_dim1);

    c__ = (real*)aligned_alloc(32, (size_t)(i__1 + 1) * c_dim1 * sizeof(real));
    if (!c__) {
        exit(1);
    }

    for (int idx = 0; idx < (i__1 + 1) * c_dim1; ++idx) {
        c__[idx] = (real)(idx % 100) * 0.01f;
    }

    t1 = 0.1f;
    t2 = 0.2f;
    t3 = 0.3f;
    t4 = 0.4f;
    t5 = 0.5f;
    t6 = 0.6f;
    v1 = 1.1f;
    v2 = 1.2f;
    v3 = 1.3f;
    v4 = 1.4f;
    v5 = 1.5f;
    v6 = 1.6f;
    sum = 0.0f;
    j = 0;
}