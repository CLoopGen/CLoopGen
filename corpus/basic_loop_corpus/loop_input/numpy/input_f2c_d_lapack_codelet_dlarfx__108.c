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

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data to target 0.01s runtime
    const size_t len = data_size / sizeof(doublereal);
    
    c__ = (doublereal*)calloc(len, sizeof(doublereal));
    if (!c__) exit(1);

    c_dim1 = 1; 
    i__1 = (integer)(len - c_dim1 - 1); 

    t1 = 1.5;

    for (size_t idx = 0; idx < len; ++idx) {
        c__[idx] = (doublereal)(idx % 1000) + 1.0;
    }
}