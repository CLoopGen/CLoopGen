#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

real *e;
integer *info;
integer i__1;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB for floats (64M elements)
    e = (real*)aligned_alloc(32, data_size * sizeof(real));
    if (!e) exit(1);

    i__1 = (integer)(data_size - 1); // ensure index bounds: i__ from 1 to i__1
    info = (integer*)aligned_alloc(32, sizeof(integer));
    if (!info) exit(1);
    *info = 0;

    for (size_t i = 0; i < data_size; ++i) {
        e[i] = (real)((i % 7) ? 1.0f : 0.0f); // sparse zeros: ~1/7 are zero
    }
}