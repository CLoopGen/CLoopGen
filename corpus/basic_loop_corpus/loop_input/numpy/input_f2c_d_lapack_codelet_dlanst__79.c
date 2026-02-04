#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
doublereal *e = NULL;
integer i__1;
doublereal d__1;
doublereal d__2;
doublereal d__3;
doublereal d__4;
doublereal d__5;
integer i__;
doublereal anorm;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024 / sizeof(doublereal); 

    d__ = (doublereal*)calloc(data_size, sizeof(doublereal));
    e = (doublereal*)calloc(data_size, sizeof(doublereal));

    if (!d__ || !e) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        d__[idx] = sin(idx * 0.01);
        e[idx] = cos(idx * 0.01);
    }

    i__1 = (integer)(data_size - 1);
    anorm = fabs(d__[1]) + fabs(e[1]) + fabs(e[0]);
}