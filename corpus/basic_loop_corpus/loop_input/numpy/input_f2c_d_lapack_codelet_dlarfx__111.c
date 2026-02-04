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
doublereal v1;
doublereal v2;
doublereal v3;
doublereal v4;
doublereal sum;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t total_elements = (data_size_mb * 1024 * 1024) / sizeof(doublereal);
    
    c_dim1 = total_elements / 5;
    if (c_dim1 < 4) {
        c_dim1 = 4;
    }
    
    i__1 = c_dim1;
    
    c__ = (doublereal*)calloc(total_elements, sizeof(doublereal));
    if (!c__) {
        exit(1);
    }
    
    t1 = 0.1;
    t2 = 0.2;
    t3 = 0.3;
    t4 = 0.4;
    v1 = 1.0;
    v2 = 1.5;
    v3 = 2.0;
    v4 = 2.5;
    sum = 0.0;
    
    for (integer i = 1; i <= i__1; ++i) {
        if (i + c_dim1 < total_elements) c__[i + c_dim1] = 1.0;
        if (i + (c_dim1 << 1) < total_elements) c__[i + (c_dim1 << 1)] = 2.0;
        if (i + c_dim1 * 3 < total_elements) c__[i + c_dim1 * 3] = 3.0;
        if (i + (c_dim1 << 2) < total_elements) c__[i + (c_dim1 << 2)] = 4.0;
    }
}