#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *a;
integer a_dim1;
integer i__1;
integer i__;
integer j;

void init_vars() {
    a_dim1 = 10000;
    i__1 = 5000;

    a = (real*)calloc((a_dim1 + 1) * (i__1 + 1), sizeof(real));
    if (!a) {
        exit(1);
    }
}