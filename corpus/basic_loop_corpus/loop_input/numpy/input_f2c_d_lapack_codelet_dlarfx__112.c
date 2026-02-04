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
doublereal t1 = 0.1;
doublereal t2 = 0.2;
doublereal t3 = 0.3;
doublereal t4 = 0.4;
doublereal t5 = 0.5;
doublereal v1 = 1.0;
doublereal v2 = 1.1;
doublereal v3 = 1.2;
doublereal v4 = 1.3;
doublereal v5 = 1.4;
doublereal sum;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t total_elements = (data_size_mb * (1 << 20)) / sizeof(doublereal);
    
    if (c__ != NULL) {
        free(c__);
    }
    c__ = (doublereal*)aligned_alloc(64, total_elements * sizeof(doublereal));
    
    for (size_t i = 0; i < total_elements; ++i) {
        c__[i] = (doublereal)(i % 1000) / 100.0;
    }

    c_dim1 = 10000;
    i__1 = c_dim1 - 1;

    t1 = 0.1; t2 = 0.2; t3 = 0.3; t4 = 0.4; t5 = 0.5;
    v1 = 1.0; v2 = 1.1; v3 = 1.2; v4 = 1.3; v5 = 1.4;
    sum = 0.0;
    j = 0;
}