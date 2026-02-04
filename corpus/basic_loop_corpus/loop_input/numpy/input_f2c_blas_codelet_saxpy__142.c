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

static real sa_data;
static real *sx_data;
static real *sy_data;
static size_t data_size;

void init_vars() {
    data_size = 67108864 / sizeof(real);  // ~256MB total for three arrays, this gives ~67M elements per array
    i__1 = (integer)data_size - 1;  // ensure sy[i__] and sx[i__] are in bounds when i__ = i__1

    sa = &sa_data;
    sx_data = (real*)aligned_alloc(32, data_size * sizeof(real));
    sy_data = (real*)aligned_alloc(32, data_size * sizeof(real));

    if (!sx_data || !sy_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    sx = sx_data;
    sy = sy_data;

    *sa = 2.5f;
    for (size_t i = 0; i < data_size; ++i) {
        sx[i] = (real)(i % 100) + 1.0f;
        sy[i] = (real)((i % 100) + 50);
    }
}