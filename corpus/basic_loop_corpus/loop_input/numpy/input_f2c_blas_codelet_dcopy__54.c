#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *dx;
doublereal *dy;
integer i__1;
integer i__;
integer mp1;

static doublereal *dx_buffer;
static doublereal *dy_buffer;
static size_t data_size;

void init_vars() {
    data_size = 64 * (1 << 20); // 64 MB of data (each array)

    dx_buffer = (doublereal *)aligned_alloc(32, data_size);
    dy_buffer = (doublereal *)aligned_alloc(32, data_size);

    if (!dx_buffer || !dy_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size / sizeof(doublereal); ++i) {
        dx_buffer[i] = (doublereal)(i % 1000) + 0.5;
        dy_buffer[i] = 0.0;
    }

    dx = dx_buffer;
    dy = dy_buffer;

    mp1 = 0;
    i__1 = (data_size / sizeof(doublereal)) - 7;

    i__ = 0;
}