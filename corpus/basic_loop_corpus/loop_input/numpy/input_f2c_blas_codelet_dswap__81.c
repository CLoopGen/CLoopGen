#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *dx;
doublereal *dy;
integer i__1;
integer i__;
doublereal dtemp;

void init_vars() {
    size_t data_size = 1 << 20; // ~16 MB of data (2^20 doubles = 8 * 2^20 bytes)
    dx = (doublereal*)aligned_alloc(32, data_size * sizeof(doublereal));
    dy = (doublereal*)aligned_alloc(32, data_size * sizeof(doublereal));

    for (size_t i = 0; i < data_size; ++i) {
        dx[i] = (doublereal)(i + 1);
        dy[i] = (doublereal)(2 * (i + 1));
    }

    i__1 = (integer)(data_size - 1);
    i__ = 0;
    dtemp = 0.0;
}