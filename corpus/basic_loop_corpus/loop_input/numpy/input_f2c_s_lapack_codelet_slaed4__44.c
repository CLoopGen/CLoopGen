#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *z__;
real *delta;
integer i__1;
integer j;
real psi;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~256 MB for two arrays (each float is 4 bytes)
    i__1 = data_size / sizeof(real);     // Number of elements

    z__ = (real *)aligned_alloc(32, data_size);
    delta = (real *)aligned_alloc(32, data_size);

    if (!z__ || !delta) {
        exit(1);
    }

    for (integer k = 0; k <= i__1; ++k) {
        z__[k] = 1.0f + (k % 7);
        delta[k] = 2.0f + (k % 5);
    }

    psi = 0.0f;
}