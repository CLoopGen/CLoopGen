#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *c__ = NULL;
integer c_dim1 = 8;
integer i__1 = 1000000; // Adjusted to achieve ~0.01 sec runtime
integer j;
doublereal t1 = 1.1;
doublereal t2 = 1.2;
doublereal t3 = 1.3;
doublereal t4 = 1.4;
doublereal t5 = 1.5;
doublereal t6 = 1.6;
doublereal t7 = 1.7;
doublereal t8 = 1.8;
doublereal v1 = 0.1;
doublereal v2 = 0.2;
doublereal v3 = 0.3;
doublereal v4 = 0.4;
doublereal v5 = 0.5;
doublereal v6 = 0.6;
doublereal v7 = 0.7;
doublereal v8 = 0.8;
doublereal sum;

void init_vars() {
    const size_t total_size = (size_t)(i__1 + 1) * (c_dim1 + 1);
    c__ = (doublereal*)calloc(total_size, sizeof(doublereal));
    if (!c__) {
        exit(1);
    }
    
    for (integer idx = 0; idx < total_size; ++idx) {
        c__[idx] = 1.0;
    }
}