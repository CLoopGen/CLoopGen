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
real t10;
real v10;
real sum;

void init_vars() {
    const int rows = 11;
    const int cols = 2097152; // ~8MB for float matrix (11 * 2M * 4 bytes)
    c_dim1 = rows;
    i__1 = cols;

    c__ = (real*)aligned_alloc(32, sizeof(real) * (rows + 1) * (cols + 1));
    if (!c__) exit(1);

    for (int i = 0; i <= rows; ++i) {
        for (int j = 0; j <= cols; ++j) {
            c__[i + j * c_dim1] = (real)(i * 314159 + j * 271828) / 1000000.0f;
        }
    }

    v1 = 0.1f; v2 = 0.2f; v3 = 0.3f; v4 = 0.4f; v5 = 0.5f;
    v6 = 0.6f; v7 = 0.7f; v8 = 0.8f; v9 = 0.9f; v10 = 1.0f;

    t1 = 0.01f; t2 = 0.02f; t3 = 0.03f; t4 = 0.04f; t5 = 0.05f;
    t6 = 0.06f; t7 = 0.07f; t8 = 0.08f; t9 = 0.09f; t10 = 0.10f;

    sum = 0.0f;
    j = 0;
}