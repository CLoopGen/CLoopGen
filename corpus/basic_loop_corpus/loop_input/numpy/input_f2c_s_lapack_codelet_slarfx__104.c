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
    const int rows = 8;
    const int cols = 1 << 20; // ~8 * 1e6 floats = ~32 MB data

    c_dim1 = rows;
    i__1 = cols;

    t1 = 0.1f; t2 = 0.2f; t3 = 0.3f; t4 = 0.4f;
    t5 = 0.5f; t6 = 0.6f; t7 = 0.7f;
    v1 = 1.0f; v2 = 1.1f; v3 = 1.2f; v4 = 1.3f;
    v5 = 1.4f; v6 = 1.5f; v7 = 1.6f;
    sum = 0.0f;

    c__ = (real*)aligned_alloc(32, sizeof(real) * rows * cols);
    if (!c__) exit(1);

    for (int i = 0; i < rows * cols; ++i) {
        c__[i] = (real)(i % 100) * 0.01f;
    }
}