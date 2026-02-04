#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
real t5;
real t6;
real t7;
real t8;
real v1;
real v2;
real v3;
real v4;
real v5;
real v6;
real v7;
real v8;
real sum;

void init_vars() {
    const int rows = 8;
    const int cols_approx = (1 << 20) / sizeof(real); // ~1MB of data
    i__1 = cols_approx > 1 ? cols_approx : 1;
    
    c_dim1 = rows;
    
    size_t total_size = (size_t)(i__1 + 1) * (c_dim1 + 1);
    c__ = (real*)calloc(total_size, sizeof(real));
    if (!c__) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    t1 = 0.1f; t2 = 0.2f; t3 = 0.3f; t4 = 0.4f;
    t5 = 0.5f; t6 = 0.6f; t7 = 0.7f; t8 = 0.8f;
    
    v1 = 1.0f; v2 = 1.1f; v3 = 1.2f; v4 = 1.3f;
    v5 = 1.4f; v6 = 1.5f; v7 = 1.6f; v8 = 1.7f;
    
    sum = 0.0f;
}