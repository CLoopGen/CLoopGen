#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

doublecomplex *za;
doublecomplex *zx;
integer i__1;
integer i__2;
integer i__3;
doublecomplex z__1;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M doubles = ~1GB for complex (adjust to hit ~0.01s runtime)
    const size_t array_len = data_size / sizeof(doublecomplex);

    zx = (doublecomplex*)aligned_alloc(32, array_len * sizeof(doublecomplex));
    if (!zx) exit(1);

    za = (doublecomplex*)aligned_alloc(32, sizeof(doublecomplex));
    if (!za) exit(1);

    // Initialize scalar values
    i__1 = (integer)(array_len - 1); // ensure i__ from 1 to i__1 stays in bounds [0..array_len-1]
    i__ = 0;
    i__2 = 0;
    i__3 = 0;

    za->r = 1.5;
    za->i = 0.8;

    z__1.r = 0.0;
    z__1.i = 0.0;

    // Initialize zx array
    for (size_t idx = 0; idx < array_len; ++idx) {
        zx[idx].r = sin((doublereal)(idx % 100)) * 0.1;
        zx[idx].i = cos((doublereal)(idx % 100)) * 0.1;
    }
}