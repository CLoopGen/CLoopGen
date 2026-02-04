#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <sys/time.h>

typedef float real;
typedef int integer;

real *z__;
integer i__1;
integer k;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of data (64M floats)
    z__ = (real *)aligned_alloc(32, data_size * sizeof(real));
    if (!z__) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        z__[i] = (real)(rand() % 1000) / 10.0f;
    }

    i__1 = (integer)((data_size - 1) / 4 + 1); // Ensure (k<<2)-3 < data_size when k <= i__1
    if (i__1 > (data_size - 1 + 3) / 4) {
        i__1 = (data_size - 1 + 3) / 4;
    }
}