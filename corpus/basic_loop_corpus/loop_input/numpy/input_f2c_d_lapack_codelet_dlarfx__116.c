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
doublereal t1 = 1.0;
doublereal t2 = 1.0;
doublereal t3 = 1.0;
doublereal t4 = 1.0;
doublereal t5 = 1.0;
doublereal t6 = 1.0;
doublereal t7 = 1.0;
doublereal t8 = 1.0;
doublereal t9 = 1.0;
doublereal v1 = 1.0;
doublereal v2 = 1.0;
doublereal v3 = 1.0;
doublereal v4 = 1.0;
doublereal v5 = 1.0;
doublereal v6 = 1.0;
doublereal v7 = 1.0;
doublereal v8 = 1.0;
doublereal v9 = 1.0;
doublereal sum = 0.0;

void init_vars() {
    const size_t total_size_mb = 64;
    const size_t element_size = sizeof(doublereal);
    const size_t desired_elements = (total_size_mb * 1024 * 1024) / element_size;
    
    c_dim1 = 1000;
    i__1 = (desired_elements / c_dim1 > 100) ? 100 : (desired_elements / c_dim1);
    
    if (i__1 < 1) i__1 = 1;
    
    size_t required_elements = i__1 + c_dim1 * 9;
    c__ = (doublereal*)calloc(required_elements, sizeof(doublereal));
    
    if (!c__) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    
    for (size_t idx = 0; idx < required_elements; ++idx) {
        c__[idx] = (doublereal)(idx % 100) / 10.0;
    }
    
    t1 = 0.1; t2 = 0.2; t3 = 0.3; t4 = 0.4; t5 = 0.5;
    t6 = 0.6; t7 = 0.7; t8 = 0.8; t9 = 0.9;
    v1 = 1.1; v2 = 1.2; v3 = 1.3; v4 = 1.4; v5 = 1.5;
    v6 = 1.6; v7 = 1.7; v8 = 1.8; v9 = 1.9;
}