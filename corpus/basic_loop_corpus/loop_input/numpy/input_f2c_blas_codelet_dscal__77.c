#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef double doublereal;
typedef int integer;

doublereal *da;
doublereal *dx;
integer i__1;
integer i__2;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of dx (each double is 8 bytes)
    dx = (doublereal*)aligned_alloc(32, data_size);
    da = (doublereal*)aligned_alloc(32, sizeof(doublereal));

    if (!dx || !da) {
        exit(1);
    }

    *da = 2.5;
    for (size_t i = 0; i < data_size / sizeof(doublereal); ++i) {
        dx[i] = (doublereal)(i + 1);
    }

    i__1 = (integer)(data_size / sizeof(doublereal)) - 1;
    i__2 = 1;
    i__ = 1;
}