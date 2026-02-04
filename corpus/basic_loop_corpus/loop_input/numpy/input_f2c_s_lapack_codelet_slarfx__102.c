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
real v1;
real v2;
real v3;
real v4;
real v5;
real sum;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient workload
    const size_t rows = 5;
    
    c_dim1 = rows;
    i__1 = data_size / (rows * sizeof(real)); // Adjust column count to fit data size
    if (i__1 == 0) i__1 = 1;

    size_t total_elements = (i__1 + 1) * (c_dim1 + 1);
    c__ = (real*)calloc(total_elements, sizeof(real));
    if (!c__) {
        exit(1);
    }

    t1 = 0.1f; t2 = 0.2f; t3 = 0.3f; t4 = 0.4f; t5 = 0.5f;
    v1 = 1.0f; v2 = 1.1f; v3 = 1.2f; v4 = 1.3f; v5 = 1.4f;
    sum = 0.0f;

    for (int col = 0; col <= i__1; ++col) {
        for (int row = 0; row <= c_dim1; ++row) {
            c__[col * c_dim1 + row] = (real)(col + row);
        }
    }
}