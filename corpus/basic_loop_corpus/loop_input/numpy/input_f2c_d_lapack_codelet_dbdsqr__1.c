#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
integer i__1;
doublereal d__1;
doublereal d__2;
doublereal d__3;
integer i__;
doublereal smax;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M doubles = 512 MB
    d__ = (doublereal*)calloc(data_size, sizeof(doublereal));
    if (!d__) exit(1);

    for (size_t idx = 0; idx < data_size; ++idx) {
        d__[idx] = sin(idx * 0.0001) * 100.0;
    }

    i__1 = (integer)(data_size - 1);
    smax = 0.0;
    i__ = 1;
}