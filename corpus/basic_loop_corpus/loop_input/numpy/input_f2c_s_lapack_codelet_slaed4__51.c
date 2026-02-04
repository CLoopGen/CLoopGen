#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;
typedef float real;

integer *i__;
real *d__;
real *delta;
integer i__1;
integer j;
real tau;

static integer static_i_value;
static real *static_d_array;
static real *static_delta_array;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data to target ~0.01s runtime
    const size_t num_elements = data_size / sizeof(real);

    static_d_array = (real*)calloc(num_elements + 1, sizeof(real));
    static_delta_array = (real*)calloc(num_elements + 1, sizeof(real));
    if (!static_d_array || !static_delta_array) {
        exit(1);
    }

    d__ = static_d_array;
    delta = static_delta_array;
    i__1 = (integer)num_elements;
    tau = 1.5f;

    static_i_value = 1;
    i__ = &static_i_value;

    for (size_t idx = 1; idx <= num_elements; ++idx) {
        d__[idx] = (real)(idx * 0.5);
    }
}