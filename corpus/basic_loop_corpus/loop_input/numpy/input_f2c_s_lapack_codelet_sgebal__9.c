#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *scale;
integer i__1;
integer i__;
integer k;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of float data
    scale = (real *)aligned_alloc(32, data_size * sizeof(real));
    if (!scale) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        scale[i] = 0.0F;
    }

    k = 0;
    i__1 = data_size - 1;
}