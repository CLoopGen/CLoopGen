#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef float real;
typedef int integer;

real *sa;
real *sx;
integer i__2;
integer i__;

static real sa_value;
static real *sx_array;
static size_t data_size;

void init_vars() {
    data_size = 64 * 1024 * 1024; // ~256 MB for sx (64M floats), ensures non-trivial runtime

    sx_array = (real*)aligned_alloc(32, data_size * sizeof(real));
    if (!sx_array) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        sx_array[i] = (real)(rand()) / RAND_MAX;
    }

    sa_value = 1.5f;

    sx = sx_array;
    sa = &sa_value;
    i__2 = (integer)(data_size - 1); 
}