#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *z__;
integer i__1;
integer k;
integer mid;
integer bsiz2;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB of data
    z__ = (real*)aligned_alloc(32, data_size * sizeof(real));
    if (!z__) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        z__[i] = 1.0F;
    }

    mid = 0;
    bsiz2 = 64 * 1024 * 1024;
    i__1 = data_size - 1;
}