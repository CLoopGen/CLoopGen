#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *work;
integer i__1;
real r__1;
real r__2;
integer i__;
real value;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t element_size = sizeof(real);
    const size_t total_elements = (data_size_mb * 1024 * 1024) / element_size;

    work = (real*)aligned_alloc(32, total_elements * sizeof(real));
    if (!work) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements; ++idx) {
        work[idx] = (real)(rand() % 1000) / 10.0f;
    }

    i__1 = (integer)(total_elements - 1);
    value = (real)(rand() % 1000) / 10.0f;
    r__1 = 0.0f;
    r__2 = 0.0f;
    i__ = 0;
}