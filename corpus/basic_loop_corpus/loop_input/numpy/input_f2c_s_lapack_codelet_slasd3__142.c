#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *u;
real *u2;
integer u_dim1;
integer u2_dim1;
integer i__1;
integer i__;

static real *u_data;
static real *u2_data;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of data (~0.01 sec on modern CPU)
    u_data = (real*)calloc(data_size, sizeof(real));
    u2_data = (real*)calloc(data_size, sizeof(real));

    if (!u_data || !u2_data) {
        exit(1);
    }

    u = u_data + 1; // Offset by 1 to allow index starting at 1
    u2 = u2_data + 1;

    u_dim1 = 1;
    u2_dim1 = 1;

    i__1 = (integer)(data_size - 2); // Ensure we don't exceed allocated bounds when accessing [i__ + dim1]
}