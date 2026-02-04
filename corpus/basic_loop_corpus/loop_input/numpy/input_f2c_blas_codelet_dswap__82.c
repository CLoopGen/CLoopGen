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
integer mp1;
doublereal dtemp;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB of data (~0.01 sec on modern CPU)
    dx = (doublereal*)aligned_alloc(32, data_size);
    dy = (doublereal*)aligned_alloc(32, data_size);

    for (size_t i = 0; i < data_size / sizeof(doublereal); ++i) {
        dx[i] = (doublereal)(i % 1000) + 1.0;
        dy[i] = (doublereal)((i + 500) % 1000) + 2.0;
    }

    mp1 = 0;
    i__1 = (integer)(data_size / sizeof(doublereal)) - 3;
    i__ = mp1;
    dtemp = 0.0;
}