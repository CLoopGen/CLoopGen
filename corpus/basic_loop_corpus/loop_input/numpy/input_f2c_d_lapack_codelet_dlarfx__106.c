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
doublereal v1;
doublereal v2;
doublereal v3;
doublereal v4;
doublereal v5;
doublereal v6;
doublereal v7;
doublereal v8;
doublereal v9;
doublereal sum;

void init_vars() {
    const integer rows = 9;
    const integer cols = 100000;
    
    c_dim1 = rows;
    i__1 = cols;
    
    t1 = 1.1; t2 = 1.2; t3 = 1.3; t4 = 1.4; t5 = 1.5;
    t6 = 1.6; t7 = 1.7; t8 = 1.8; t9 = 1.9;
    v1 = 0.1; v2 = 0.2; v3 = 0.3; v4 = 0.4; v5 = 0.5;
    v6 = 0.6; v7 = 0.7; v8 = 0.8; v9 = 0.9;
    
    c__ = (doublereal*)calloc(rows * cols, sizeof(doublereal));
    if (!c__) {
        exit(1);
    }
    
    for (integer j = 0; j < rows * cols; ++j) {
        c__[j] = (doublereal)(j % 17) * 0.01;
    }
}