#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

real *z__;
real *delta;
real *work;
integer i__1;
integer j;
real psi;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of total data (64M elements * 4 bytes * 4 arrays)
    i__1 = (integer)data_size;

    z__ = (real*)aligned_alloc(32, data_size * sizeof(real));
    delta = (real*)aligned_alloc(32, data_size * sizeof(real));
    work = (real*)aligned_alloc(32, data_size * sizeof(real));

    for (size_t i = 0; i < data_size; ++i) {
        z__[i] = (real)(rand() % 100) / 10.0f;
        delta[i] = (real)(rand() % 100 + 1) / 10.0f; // Avoid zero
        work[i] = (real)(rand() % 100 + 1) / 10.0f;  // Avoid zero
    }

    psi = 0.0f;
    j = 0;
}