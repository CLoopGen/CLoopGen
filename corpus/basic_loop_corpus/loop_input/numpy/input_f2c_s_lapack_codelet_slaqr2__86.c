#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *t;
integer t_dim1;
integer i__1;
integer j;

void init_vars() {
    t_dim1 = 10000;
    i__1 = 5000;

    size_t total_size = (i__1 + 3) * (t_dim1 + 1);
    t = (real*)calloc(total_size, sizeof(real));
    if (!t) {
        exit(1);
    }
}