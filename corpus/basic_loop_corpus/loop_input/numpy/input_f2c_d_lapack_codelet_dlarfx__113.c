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
doublereal t4;
doublereal t5;
doublereal t6;
doublereal v1;
doublereal v2;
doublereal v3;
doublereal v4;
doublereal v5;
doublereal v6;
doublereal sum;

void init_vars() {
    t1 = 0.1; t2 = 0.2; t3 = 0.3; t4 = 0.4; t5 = 0.5; t6 = 0.6;
    v1 = 1.1; v2 = 1.2; v3 = 1.3; v4 = 1.4; v5 = 1.5; v6 = 1.6;
    sum = 0.0;

    c_dim1 = 1024;
    i__1 = 1000;

    size_t total_size = c_dim1 * 7;
    c__ = (doublereal*)calloc(total_size, sizeof(doublereal));
    if (!c__) {
        exit(1);
    }

    for (size_t i = 0; i < total_size; ++i) {
        c__[i] = (doublereal)(i % 100) / 10.0;
    }
}