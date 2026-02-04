#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef float real;
typedef int integer;

real *c__ = NULL;
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
    // Set parameters for ~0.01 sec runtime on modern CPU
    // Estimate: each iteration does 8 flops, aim for ~100M operations at 10 GFLOPS
    i__1 = 1 << 20;  // 1M iterations
    c_dim1 = 1 << 10; // 1K stride -> total matrix size ~4MB (assuming row-major, 4 rows)

    t1 = 0.1f;
    t2 = 0.2f;
    t3 = 0.3f;
    t4 = 0.4f;
    v1 = 1.0f;
    v2 = 1.5f;
    v3 = 2.0f;
    v4 = 2.5f;
    sum = 0.0f;

    // Allocate memory for c__: we access up to j + (c_dim1 << 2) = j + 4*c_dim1
    // Max index: i__1 + 4*c_dim1 <= 1<<20 + 4*(1<<10) ≈ 1<<20 + 4096
    size_t alloc_size = i__1 + (c_dim1 << 2) + 10; // add padding
    c__ = (real*)aligned_alloc(32, alloc_size * sizeof(real));
    if (!c__) {
        exit(1);
    }

    // Initialize c__ array to avoid undefined behavior
    for (size_t i = 0; i < alloc_size; ++i) {
        c__[i] = (real)(i % 1000) / 1000.0f;
    }
}