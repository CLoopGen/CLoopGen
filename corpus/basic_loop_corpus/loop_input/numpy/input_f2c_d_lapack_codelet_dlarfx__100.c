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
doublereal t2;
doublereal t3;
doublereal v1;
doublereal v2;
doublereal v3;
doublereal sum;

void init_vars() {
    t1 = 0.1;
    t2 = 0.2;
    t3 = 0.3;
    v1 = 1.5;
    v2 = 2.5;
    v3 = 3.5;
    sum = 0.0;

    c_dim1 = 4;
    i__1 = 5000000;

    size_t total_size = (size_t)(i__1 + 1) * c_dim1 * sizeof(doublereal);
    c__ = (doublereal*)calloc(total_size / sizeof(doublereal), sizeof(doublereal));
    if (c__ == NULL) {
        exit(1);
    }

    for (int idx = 0; idx <= i__1 * c_dim1 + 3; ++idx) {
        c__[idx] = (doublereal)(idx % 100) * 0.01;
    }
}