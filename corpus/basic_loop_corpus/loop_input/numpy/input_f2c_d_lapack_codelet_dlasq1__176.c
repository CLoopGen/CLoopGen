#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
integer i__1;
doublereal d__1;
doublereal d__2;
integer i__;
doublereal sigmx;

void init_vars() {
    const size_t data_size_bytes = 64 * 1024 * 1024; // ~64 MB for ~0.01 sec runtime estimate
    const size_t num_elements = data_size_bytes / sizeof(doublereal);

    i__1 = (integer)num_elements;

    d__ = (doublereal*)calloc(num_elements + 1, sizeof(doublereal));
    if (!d__) {
        exit(EXIT_FAILURE);
    }

    for (size_t idx = 1; idx <= num_elements; ++idx) {
        d__[idx] = sin((double)idx) * 100.0;
    }

    sigmx = -INFINITY;
    i__ = 1;
    d__1 = 0.0;
    d__2 = 0.0;
}