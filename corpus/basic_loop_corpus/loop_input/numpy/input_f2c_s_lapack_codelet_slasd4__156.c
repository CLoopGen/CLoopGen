#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *delta;
real *work;
integer i__1;
integer j;
real eta;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~256 MB total for two arrays (each 128 MB)
    i__1 = (integer)(data_size / sizeof(real)) - 1; // ensure valid index range

    delta = (real *)aligned_alloc(32, (i__1 + 1) * sizeof(real));
    work = (real *)aligned_alloc(32, (i__1 + 1) * sizeof(real));

    eta = 0.001f;

    for (integer idx = 0; idx <= i__1; ++idx) {
        delta[idx] = (real)(idx % 1000);
        work[idx] = (real)(idx % 1000);
    }
}