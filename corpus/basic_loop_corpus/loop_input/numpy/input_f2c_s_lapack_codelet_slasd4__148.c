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
real dpsi;
real temp;
real erretm;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of total data (64M floats)
    z__ = (real*)aligned_alloc(32, data_size * sizeof(real));
    delta = (real*)aligned_alloc(32, data_size * sizeof(real));
    work = (real*)aligned_alloc(32, data_size * sizeof(real));

    for (size_t i = 0; i < data_size; ++i) {
        z__[i] = (real)(rand() % 100 + 1);
        delta[i] = (real)(rand() % 100 + 1);
        work[i] = (real)(rand() % 100 + 1);
    }

    i__1 = (integer)(data_size - 1);

    psi = 0.0f;
    dpsi = 0.0f;
    temp = 0.0f;
    erretm = 0.0f;
}