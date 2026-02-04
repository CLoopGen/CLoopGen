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
integer mp1;
real stemp;

static real sx_data[64 << 20] __attribute__((aligned(32)));
static real sy_data[64 << 20] __attribute__((aligned(32)));

void init_vars() {
    const size_t data_size = 64 << 20; // 64 million elements, ~256 MB per array

    for (size_t i = 0; i < data_size; ++i) {
        sx_data[i] = (real)(i + 1);
        sy_data[i] = (real)(-(i + 1));
    }

    sx = sx_data;
    sy = sy_data;
    mp1 = 0;
    i__1 = (integer)(data_size - 3); // Ensure i__+2 is in bounds
    i__ = 0;
    stemp = 0.0f;
}