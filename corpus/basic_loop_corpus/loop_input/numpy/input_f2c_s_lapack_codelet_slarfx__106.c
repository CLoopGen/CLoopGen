#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

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
real sum;

void loop(void);

void init_vars() {
    c_dim1 = 10;
    i__1 = (1 << 20) / sizeof(real); // ~1MB of data, about 262k iterations
    int total_size = (i__1 + 1) * (c_dim1 + 1);
    c__ = (real*)calloc(total_size, sizeof(real));
    
    if (!c__) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    t1 = 1.0f; t2 = 2.0f; t3 = 3.0f; t4 = 4.0f; t5 = 5.0f;
    t6 = 6.0f; t7 = 7.0f; t8 = 8.0f; t9 = 9.0f;
    v1 = 0.1f; v2 = 0.2f; v3 = 0.3f; v4 = 0.4f; v5 = 0.5f;
    v6 = 0.6f; v7 = 0.7f; v8 = 0.8f; v9 = 0.9f;
    sum = 0.0f;

    for (int i = 1; i <= i__1; ++i) {
        for (int k = 1; k <= 9; ++k) {
            c__[i * c_dim1 + k] = (real)(i % 100 + k);
        }
    }
}