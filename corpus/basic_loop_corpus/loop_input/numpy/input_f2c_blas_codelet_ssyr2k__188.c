#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *beta;
real *c__;
integer c_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    i__1 = 500;
    c_dim1 = i__1 + 10;
    
    beta = (real*)malloc(sizeof(real));
    *beta = 1.5f;

    size_t c_size = (i__1 + 1) * (c_dim1 + 1);
    c__ = (real*)calloc(c_size, sizeof(real));
    
    for (size_t idx = 0; idx < c_size; ++idx) {
        c__[idx] = (real)(idx % 100);
    }
}