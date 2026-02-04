#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *c__ = NULL;
integer c_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    i__1 = 4096;
    c_dim1 = i__1 + 100;

    size_t total_size = (size_t)(i__1 + 1) * (c_dim1 + 1) * sizeof(real);
    c__ = (real*)calloc(total_size / sizeof(real), sizeof(real));
    if (!c__) {
        exit(1);
    }
}