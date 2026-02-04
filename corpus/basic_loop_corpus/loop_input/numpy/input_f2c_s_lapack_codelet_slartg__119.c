#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

real *r__ = NULL;
integer i__1;
integer i__;
real safmn2;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to ensure measurable execution time
    real *data = (real *)aligned_alloc(32, data_size);
    if (!data) exit(1);

    for (size_t i = 0; i < data_size / sizeof(real); ++i) {
        data[i] = 1.0f + i % 100;
    }

    r__ = &data[0];
    i__1 = data_size / sizeof(real);
    i__ = 1;
    safmn2 = 0.5f;
}