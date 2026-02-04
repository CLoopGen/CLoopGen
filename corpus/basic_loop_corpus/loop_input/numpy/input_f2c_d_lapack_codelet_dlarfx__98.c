#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *c__ = NULL;
integer c_dim1;
integer i__1;
integer j;
doublereal t1;

void init_vars() {
    t1 = 2.5;
    c_dim1 = 1024;
    i__1 = 100000;

    size_t array_size = (i__1 + 1) * (c_dim1 + 1);
    c__ = (doublereal *)calloc(array_size, sizeof(doublereal));
    if (c__ == NULL) {
        exit(1);
    }

    for (integer idx = 0; idx <= i__1; ++idx) {
        c__[idx * c_dim1 + 1] = 1.0;
    }
}