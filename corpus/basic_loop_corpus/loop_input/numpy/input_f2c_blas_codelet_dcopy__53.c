#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef double doublereal;
typedef int integer;

doublereal *dx;
doublereal *dy;
integer i__1;
integer i__;

static doublereal *dx_data;
static doublereal *dy_data;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of total data (2 arrays), adjust as needed for timing
    const size_t num_elements = data_size / sizeof(doublereal);

    dx_data = (doublereal*)aligned_alloc(32, data_size);
    dy_data = (doublereal*)aligned_alloc(32, data_size);

    if (!dx_data || !dy_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < num_elements; ++i) {
        dx_data[i] = (doublereal)(i + 1); // arbitrary initialization
        dy_data[i] = 0.0;
    }

    dx = dx_data - 1; // shift base index to 1-based indexing
    dy = dy_data - 1;
    i__1 = (integer)num_elements;
    i__ = 0;
}