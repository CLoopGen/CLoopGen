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
    const integer num_cols = 11;
    const integer num_rows = 20000000; // ~1.6 GB of data (20M * 11 * 8 bytes)
    
    c_dim1 = num_rows;
    i__1 = num_rows;

    t1 = 0.1; t2 = 0.2; t3 = 0.3; t4 = 0.4; t5 = 0.5;
    t6 = 0.6; t7 = 0.7; t8 = 0.8; t9 = 0.9; t10 = 1.0;
    v1 = 1.1; v2 = 1.2; v3 = 1.3; v4 = 1.4; v5 = 1.5;
    v6 = 1.6; v7 = 1.7; v8 = 1.8; v9 = 1.9; v10 = 2.0;

    c__ = (doublereal*)calloc(num_rows * num_cols, sizeof(doublereal));
    if (!c__) {
        exit(1);
    }

    for (integer i = 0; i < num_rows * num_cols; ++i) {
        c__[i] = (doublereal)(i % 100) / 10.0;
    }
}