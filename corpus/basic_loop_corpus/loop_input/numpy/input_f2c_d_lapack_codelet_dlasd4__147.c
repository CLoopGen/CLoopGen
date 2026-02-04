#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;
typedef double doublereal;

integer i__1 = 0;
integer j = 0;
doublereal eta = 0.0;

integer i__storage = 0;
integer *i__ = &i__storage;

doublereal d_storage[262144]; 
doublereal *d__ = d_storage;

doublereal delta_storage[262144];
doublereal *delta = delta_storage;

doublereal work_storage[262144];
doublereal *work = work_storage;

void init_vars() {
    const size_t array_size = 262144; 
    i__1 = (integer)(array_size - 1); 
    *i__ = 1; 

    eta = 1.5e-8;

    for (size_t idx = 0; idx <= (size_t)i__1; ++idx) {
        d__[idx] = (doublereal)(idx + 1) * 1.5;
    }

    memset(delta, 0, array_size * sizeof(doublereal));
    memset(work, 0, array_size * sizeof(doublereal));
}