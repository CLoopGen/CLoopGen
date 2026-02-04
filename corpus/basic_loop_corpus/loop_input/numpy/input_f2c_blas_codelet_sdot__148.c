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
integer i__1;
integer i__;
real stemp;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB for two arrays of floats (64M elements each)
    i__1 = (integer)(data_size / sizeof(real));
    stemp = 0.0f;

    sx = (real*)aligned_alloc(32, (i__1 + 1) * sizeof(real));
    sy = (real*)aligned_alloc(32, (i__1 + 1) * sizeof(real));

    if (!sx || !sy) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (integer i = 1; i <= i__1; ++i) {
        sx[i] = (real)(sin(i) * 100.0);
        sy[i] = (real)(cos(i) * 100.0);
    }
}