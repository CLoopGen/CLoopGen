#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *t;
integer t_dim1;
integer i__1;
integer j;

void init_vars() {
    t_dim1 = 1024;
    i__1 = 50000;

    size_t total_size = (i__1 + 3) * (t_dim1 + 1) * sizeof(doublereal);
    if (total_size < 1024 * 1024) {
        total_size = 1024 * 1024;
        i__1 = (total_size / sizeof(doublereal)) / (t_dim1 + 1);
    }

    t = (doublereal *)calloc((i__1 + 3) * (t_dim1 + 1), sizeof(doublereal));
    if (!t) {
        exit(1);
    }
}