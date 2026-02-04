#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *sr;
doublereal *si;
integer i__1;
integer i__;
doublereal swap;

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024;
    const size_t element_size = sizeof(doublereal);
    const size_t n_elements = total_size / (2 * element_size);

    sr = (doublereal*)aligned_alloc(32, n_elements * element_size);
    si = (doublereal*)aligned_alloc(32, n_elements * element_size);

    for (size_t i = 0; i < n_elements; ++i) {
        sr[i] = sin(i * 0.01);
        si[i] = cos(i * 0.01);
    }

    i__1 = (integer)(n_elements - 3);
    if (i__1 <= 0) i__1 = 1;

    i__ = 1;
    swap = 0.0;
}