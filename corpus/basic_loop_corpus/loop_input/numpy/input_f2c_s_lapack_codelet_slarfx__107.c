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
    const int rows = 10;
    const int cols = 20000;
    
    c_dim1 = rows;
    i__1 = cols;
    
    t1 = 0.1f; t2 = 0.2f; t3 = 0.3f; t4 = 0.4f; t5 = 0.5f;
    t6 = 0.6f; t7 = 0.7f; t8 = 0.8f; t9 = 0.9f; t10 = 1.0f;
    
    v1 = 1.0f; v2 = 0.9f; v3 = 0.8f; v4 = 0.7f; v5 = 0.6f;
    v6 = 0.5f; v7 = 0.4f; v8 = 0.3f; v9 = 0.2f; v10 = 0.1f;
    
    sum = 0.0f;
    
    c__ = (real*)calloc(rows * cols, sizeof(real));
    if (!c__) {
        exit(1);
    }
    
    for (int i = 0; i < rows * cols; ++i) {
        c__[i] = (real)(i % 17) * 0.05f;
    }
}