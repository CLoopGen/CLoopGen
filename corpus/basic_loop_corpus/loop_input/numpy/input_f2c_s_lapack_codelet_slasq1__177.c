#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

real *work;
integer i__1;
real r__1;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of data (64M floats)
    work = (real*)aligned_alloc(32, data_size * sizeof(real));
    if (!work) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        work[i] = (real)(i % 1000) / 100.0f;
    }

    i__1 = (integer)(data_size - 1);
    r__1 = 0.0f;
    i__ = 0;
}