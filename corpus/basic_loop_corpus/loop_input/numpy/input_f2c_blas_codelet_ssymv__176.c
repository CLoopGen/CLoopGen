#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef float real;
typedef int integer;

real *beta;
real *y;
integer i__1;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB for floats (64M elements)
    y = (real*)aligned_alloc(32, data_size * sizeof(real));
    if (!y) exit(1);

    beta = (real*)aligned_alloc(32, sizeof(real));
    if (!beta) exit(1);

    *beta = 1.5f;
    i__1 = (integer)(data_size - 1); 

    for (size_t i = 0; i <= i__1; ++i) {
        y[i] = (real)(i % 1000) + 1.0f;
    }

    i__ = 0;
}