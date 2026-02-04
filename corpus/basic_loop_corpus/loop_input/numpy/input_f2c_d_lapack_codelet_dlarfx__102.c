#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *c__ = NULL;
integer c_dim1;
integer i__1;
integer j;
doublereal t1;
doublereal t2;
doublereal t3;
doublereal t4;
doublereal t5;
doublereal v1;
doublereal v2;
doublereal v3;
doublereal v4;
doublereal v5;
doublereal sum;

void init_vars() {
    // Set constants
    t1 = 0.1; t2 = 0.2; t3 = 0.3; t4 = 0.4; t5 = 0.5;
    v1 = 1.1; v2 = 1.2; v3 = 1.3; v4 = 1.4; v5 = 1.5;

    // Set dimensions: aim for ~64MB of data to target ~0.01s runtime
    // We use 5 columns, and adjust rows so that total size is about 64M-256M
    // Each element is sizeof(double) = 8 bytes
    // Let's target around 16M elements -> 16M * 8 = 128MB
    const int num_cols = 5;
    const int num_rows = 16 * 1024 * 1024 / num_cols; // ~3.2M rows for 5 cols
    i__1 = num_rows;
    c_dim1 = num_cols;

    // Allocate column-major matrix (Fortran-style), size c_dim1 x i__1
    c__ = (doublereal*)calloc(num_rows * num_cols, sizeof(doublereal));
    if (!c__) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize matrix with some data
    for (int i = 0; i < num_rows * num_cols; ++i) {
        c__[i] = (doublereal)(i % 100 + 1) / 100.0;
    }

    // Initialize sum
    sum = 0.0;
}