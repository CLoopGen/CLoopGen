#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

real *sx;
real *sy;
real *c__;
real *s;
integer i__1;
integer i__;
real stemp;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB for two arrays of floats (sx, sy)

    sx = (real*)aligned_alloc(32, data_size * sizeof(real));
    sy = (real*)aligned_alloc(32, data_size * sizeof(real));

    if (!sx || !sy) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    c__ = (real*)aligned_alloc(32, sizeof(real));
    s = (real*)aligned_alloc(32, sizeof(real));

    if (!c__ || !s) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    *c__ = 0.86602540378f; // cos(30°)
    *s = 0.5f;             // sin(30°)

    for (size_t i = 0; i < data_size; ++i) {
        sx[i] = (real)(rand()) / RAND_MAX;
        sy[i] = (real)(rand()) / RAND_MAX;
    }

    i__1 = (integer)(data_size - 1);
    i__ = 1;
    stemp = 0.0f;
}