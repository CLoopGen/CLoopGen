#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *d__;
real *delta;
integer i__1;
integer j;
integer ip1;
real tau;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of total data (each float is 4 bytes)

    d__ = (real *)calloc(data_size, sizeof(real));
    delta = (real *)calloc(data_size, sizeof(real));

    if (!d__ || !delta) {
        exit(1);
    }

    i__1 = (integer)(data_size - 2);
    ip1 = i__1 + 1;
    tau = 1.5f;

    for (integer idx = 0; idx < data_size; ++idx) {
        d__[idx] = (real)(idx * 2.5);
    }
}