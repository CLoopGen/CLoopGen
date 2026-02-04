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

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data to target ~0.01s runtime
    c__ = (real*)aligned_alloc(32, data_size * sizeof(real));
    if (!c__) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        c__[i] = (real)(i % 1000) / 100.0f;
    }

    t1 = 1.5f;
    c_dim1 = 0; 
    i__1 = (integer)(data_size - 1); 
}