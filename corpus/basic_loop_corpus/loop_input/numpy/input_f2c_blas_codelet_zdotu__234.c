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

doublecomplex *zx;
doublecomplex *zy;
integer i__1;
integer i__2;
integer i__3;
doublecomplex z__1;
doublecomplex z__2;
integer i__;
doublecomplex ztemp;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~1GB total for both arrays (each ~512MB)
    const size_t num_elements = data_size / sizeof(doublecomplex);

    zx = (doublecomplex*)aligned_alloc(32, num_elements * sizeof(doublecomplex));
    zy = (doublecomplex*)aligned_alloc(32, num_elements * sizeof(doublecomplex));

    for (size_t idx = 0; idx < num_elements; ++idx) {
        zx[idx].r = sin(idx * 0.001);
        zx[idx].i = cos(idx * 0.001);
        zy[idx].r = cos(idx * 0.0015);
        zy[idx].i = sin(idx * 0.0015);
    }

    i__1 = (integer)(num_elements > 1000000 ? 1000000 : num_elements - 1); 
    i__ = 0;
    ztemp.r = 0.0;
    ztemp.i = 0.0;
    z__1.r = 0.0;
    z__1.i = 0.0;
    z__2.r = 0.0;
    z__2.i = 0.0;
    i__2 = 0;
    i__3 = 0;
}