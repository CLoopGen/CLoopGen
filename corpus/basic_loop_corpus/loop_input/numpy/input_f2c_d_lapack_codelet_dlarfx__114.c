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
doublereal t6;
doublereal t7;
doublereal v1;
doublereal v2;
doublereal v3;
doublereal v4;
doublereal v5;
doublereal v6;
doublereal v7;
doublereal sum;

void init_vars() {
    const size_t target_size = 128 * 1024 * 1024; // ~128MB of data
    c_dim1 = (target_size / sizeof(doublereal)) / 8; // Ensure we have at least 8 columns
    if (c_dim1 < 1000) c_dim1 = 1000;
    i__1 = c_dim1; // Number of iterations in the loop

    size_t alloc_size = (c_dim1 + 1) * 8 * sizeof(doublereal); // 8 columns, 1-based indexing
    c__ = (doublereal*)calloc(alloc_size / sizeof(doublereal), sizeof(doublereal));
    if (!c__) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    t1 = 0.1; t2 = 0.2; t3 = 0.3; t4 = 0.4;
    t5 = 0.5; t6 = 0.6; t7 = 0.7;
    v1 = 1.0; v2 = 1.1; v3 = 1.2; v4 = 1.3;
    v5 = 1.4; v6 = 1.5; v7 = 1.6;

    for (integer col = 1; col <= 7; ++col) {
        for (integer row = 1; row <= i__1; ++row) {
            c__[row + col * c_dim1] = (doublereal)(row % 100 + col);
        }
    }
}