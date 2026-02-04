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
real t6 = 0.0f;
real v1 = 0.0f;
real v2 = 0.0f;
real v3 = 0.0f;
real v4 = 0.0f;
real v5 = 0.0f;
real v6 = 0.0f;
real sum = 0.0f;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; // Aim for ~64MB to ensure loop takes time
    c_dim1 = 10000; // Column stride
    i__1 = (target_bytes / sizeof(real)) / 7;   // Ensure we access up to index j + 6*c_dim1
    if (i__1 > c_dim1) i__1 = c_dim1 - 1;       // Keep within safe bounds

    size_t array_size = c_dim1 * 7 + i__1 + 1;
    c__ = (real*)calloc(array_size, sizeof(real));
    if (!c__) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    t1 = 0.1f; t2 = 0.2f; t3 = 0.3f; t4 = 0.4f; t5 = 0.5f; t6 = 0.6f;
    v1 = 1.1f; v2 = 1.2f; v3 = 1.3f; v4 = 1.4f; v5 = 1.5f; v6 = 1.6f;

    for (size_t i = 1; i <= i__1; ++i) {
        c__[i + c_dim1] = 1.0f;
        c__[i + (c_dim1 << 1)] = 2.0f;
        c__[i + c_dim1 * 3] = 3.0f;
        c__[i + (c_dim1 << 2)] = 4.0f;
        c__[i + c_dim1 * 5] = 5.0f;
        c__[i + c_dim1 * 6] = 6.0f;
    }
}