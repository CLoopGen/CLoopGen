#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *c__;
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
    const size_t element_size = sizeof(doublereal);
    const size_t elements_per_row = 4;
    const size_t total_elements = (data_size_mb * 1024 * 1024) / element_size;
    
    c_dim1 = elements_per_row;
    i__1 = total_elements / elements_per_row;
    
    c__ = (doublereal*)calloc(total_elements, element_size);
    
    t1 = 0.1;
    t2 = 0.2;
    t3 = 0.3;
    t4 = 0.4;
    v1 = 1.0;
    v2 = 1.5;
    v3 = 2.0;
    v4 = 2.5;
    sum = 0.0;
    
    for (size_t idx = 0; idx < total_elements; ++idx) {
        c__[idx] = (doublereal)(idx % 17) * 0.05;
    }
}