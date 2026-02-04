#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *dx;
doublereal *dy;
doublereal *c__;
doublereal *s;
integer i__1;
integer i__;
doublereal dtemp;

void init_vars() {
    const size_t data_size = 1 << 20; // 1M elements, ~8MB per array
    i__1 = (integer)data_size;
    i__ = 1;

    dx = (doublereal*)aligned_alloc(32, data_size * sizeof(doublereal));
    dy = (doublereal*)aligned_alloc(32, data_size * sizeof(doublereal));
    if (!dx || !dy) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    c__ = (doublereal*)aligned_alloc(32, sizeof(doublereal));
    s = (doublereal*)aligned_alloc(32, sizeof(doublereal));
    if (!c__ || !s) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    *c__ = 0.86602540378; // cos(30°)
    *s = 0.5;             // sin(30°)

    for (size_t i = 0; i < data_size; ++i) {
        dx[i] = sin((double)i);
        dy[i] = cos((double)i);
    }

    dtemp = 0.0;
}