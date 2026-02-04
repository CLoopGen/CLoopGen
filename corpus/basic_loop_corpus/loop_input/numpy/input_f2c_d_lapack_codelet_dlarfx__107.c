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
doublereal t7;
doublereal t8;
doublereal t9;
doublereal t10;
doublereal v1;
doublereal v2;
doublereal v3;
doublereal v4;
doublereal v5;
doublereal v6;
doublereal v7;
doublereal v8;
doublereal v9;
doublereal v10;
doublereal sum;

void init_vars() {
    const integer rows = 10;
    const integer cols = 20000000;
    c_dim1 = rows;
    i__1 = cols;

    c__ = (doublereal*)calloc(rows * cols, sizeof(doublereal));
    if (!c__) {
        exit(1);
    }

    t1 = 1.0;   t2 = 1.1;   t3 = 1.2;   t4 = 1.3;   t5 = 1.4;
    t6 = 1.5;   t7 = 1.6;   t8 = 1.7;   t9 = 1.8;   t10 = 1.9;
    v1 = 0.1;   v2 = 0.2;   v3 = 0.3;   v4 = 0.4;   v5 = 0.5;
    v6 = 0.6;   v7 = 0.7;   v8 = 0.8;   v9 = 0.9;   v10 = 1.0;

    for (integer i = 0; i < rows * cols; ++i) {
        c__[i] = 1.0;
    }
}