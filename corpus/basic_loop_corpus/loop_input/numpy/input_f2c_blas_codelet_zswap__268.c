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
integer i__;
doublecomplex ztemp;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~1GB total for two arrays (each ~512MB)
    const size_t n = data_size / sizeof(doublecomplex);

    zx = (doublecomplex*)aligned_alloc(32, n * sizeof(doublecomplex));
    zy = (doublecomplex*)aligned_alloc(32, n * sizeof(doublecomplex));

    for (size_t idx = 0; idx < n; ++idx) {
        zx[idx].r = sin(idx);
        zx[idx].i = cos(idx);
        zy[idx].r = cos(idx);
        zy[idx].i = sin(idx);
    }

    i__1 = (integer)(n - 1); 
    i__ = 0;
    i__2 = 0;
    i__3 = 0;
}