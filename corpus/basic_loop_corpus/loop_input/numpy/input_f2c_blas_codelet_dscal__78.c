#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef double doublereal;
typedef int integer;

doublereal *da;
doublereal *dx;
integer i__2;
integer i__;

void init_vars() {
    const size_t data_size = 1 << 24; // 16 million elements, ~128 MB for doubles
    dx = (doublereal*)aligned_alloc(32, data_size * sizeof(doublereal));
    if (!dx) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        dx[i] = (doublereal)(rand() % 1000) / 10.0;
    }

    da = (doublereal*)aligned_alloc(32, sizeof(doublereal));
    if (!da) {
        exit(1);
    }
    *da = 1.25;

    i__2 = (integer)(data_size - 1);
}