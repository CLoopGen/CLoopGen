#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *sa;
real *sx;
real *sy;
integer i__1;
integer i__;
integer mp1;

static real sa_data;
static real *sx_data;
static real *sy_data;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB of data for sufficient runtime (~0.01 sec on modern CPU)

    sa = &sa_data;
    sx_data = (real*)aligned_alloc(32, data_size * sizeof(real));
    sy_data = (real*)aligned_alloc(32, data_size * sizeof(real));

    if (!sx_data || !sy_data) {
        exit(1);
    }

    sx = sx_data;
    sy = sy_data;

    for (size_t i = 0; i < data_size; ++i) {
        sx[i] = (real)(i % 100) + 1.0f;
        sy[i] = (real)((i % 75) + 10);
    }
    sa_data = 1.5f;

    mp1 = 0;
    i__1 = (integer)(data_size - 4); // Ensure i__+3 does not exceed bounds
}