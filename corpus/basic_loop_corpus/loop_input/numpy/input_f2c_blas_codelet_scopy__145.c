#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *sx;
real *sy;
integer i__1;
integer i__;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~256 MB for two arrays (each float is 4 bytes)

    sx = (real*)aligned_alloc(32, data_size * sizeof(real));
    sy = (real*)aligned_alloc(32, data_size * sizeof(real));

    if (!sx || !sy) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        sx[i] = (real)(i % 1000) / 10.0f;
        sy[i] = 0.0f;
    }

    i__1 = (integer)(data_size - 1);
    i__ = 0;
}