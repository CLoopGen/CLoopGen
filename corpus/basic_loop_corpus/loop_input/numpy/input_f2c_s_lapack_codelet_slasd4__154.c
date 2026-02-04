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
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of total data (64M elements × 4 bytes)
    i__1 = (integer)(data_size / sizeof(real));

    z__ = (real*)aligned_alloc(32, data_size);
    delta = (real*)aligned_alloc(32, data_size);
    work = (real*)aligned_alloc(32, data_size);

    for (integer i = 0; i < i__1; ++i) {
        z__[i] = (real)(rand() % 100) / 10.0f + 1.0f;
        delta[i] = (real)(rand() % 100) / 20.0f + 1.0f;
        work[i] = (real)(rand() % 100) / 15.0f + 1.0f;
    }

    psi = 0.0f;
    dpsi = 0.0f;
    temp = 0.0f;
    erretm = 0.0f;
}