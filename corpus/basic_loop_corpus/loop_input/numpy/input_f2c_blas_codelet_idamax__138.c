#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *dx;
integer ret_val;
integer i__1;
doublereal d__1;
integer i__;
doublereal dmax__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M doubles = 512MB
    dx = (doublereal*)calloc(data_size, sizeof(doublereal));
    if (!dx) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        dx[idx] = ((double)rand() / RAND_MAX) * 200.0 - 100.0; // Random values in [-100, 100]
    }

    i__1 = (integer)(data_size - 1); 
    ret_val = 1;
    dmax__ = 0.0;
    i__ = 1;
    d__1 = 0.0;
}