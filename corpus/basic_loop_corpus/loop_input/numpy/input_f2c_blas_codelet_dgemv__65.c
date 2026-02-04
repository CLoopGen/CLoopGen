#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef double doublereal;
typedef int integer;

doublereal *beta;
doublereal *y;
integer i__1;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of y (each double is 8 bytes)
    i__1 = (integer)(data_size / sizeof(doublereal)) - 1; // ensure index within bounds

    posix_memalign((void**)&y, 32, (i__1 + 1) * sizeof(doublereal));
    if (!y) {
        exit(1);
    }

    for (integer i = 0; i <= i__1; ++i) {
        y[i] = (doublereal)(i % 1000) + 1.0;
    }

    posix_memalign((void**)&beta, 32, sizeof(doublereal));
    if (!beta) {
        exit(1);
    }
    *beta = 2.5;
    i__ = 1;
}