#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *d__ = NULL;
integer i__1;
real r__1;
real r__2;
real r__3;
integer i__;
real smax;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t total_elements = (data_size_mb * 1024 * 1024) / sizeof(real);
    
    d__ = (real*)calloc(total_elements, sizeof(real));
    if (!d__) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements; ++idx) {
        d__[idx] = (real)(rand() % 1000) * (rand() % 2 ? 1.0 : -1.0);
    }

    i__1 = (integer)(total_elements - 1);
    if (i__1 <= 0) {
        i__1 = 1;
    }

    smax = 0.0f;
    r__1 = 0.0f;
    r__2 = 0.0f;
    r__3 = 0.0f;
    i__ = 1;
}