#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *m;
real *c__;
integer c_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    i__1 = 5000;
    m = (integer*)malloc(sizeof(integer));
    *m = 5000;
    c_dim1 = 5000;
    size_t c_size = (i__1 + 1) * (*m + 1);
    c__ = (real*)calloc(c_size, sizeof(real));
}

void loop();