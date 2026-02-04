#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *tau;
integer i__1;
integer i__;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime (~0.01 sec)
    tau = (real*)aligned_alloc(32, data_size);
    if (!tau) exit(1);

    i__1 = (integer)(data_size / sizeof(real)) - 1; // ensure no out-of-bounds access
    for (size_t i = 0; i <= i__1; ++i) {
        tau[i] = 1.0F;
    }
}