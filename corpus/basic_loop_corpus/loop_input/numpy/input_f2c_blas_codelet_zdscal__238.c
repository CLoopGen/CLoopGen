#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;
typedef int integer;

doublereal *da;
doublecomplex *zx;
integer i__1;
integer i__2;
integer i__3;
doublecomplex z__1;
doublecomplex z__2;
integer i__;

void init_vars() {
    i__1 = 10000000; // Size to make loop run ~0.01 seconds

    da = (doublereal*)malloc(sizeof(doublereal));
    *da = 2.5;

    zx = (doublecomplex*)malloc((i__1 + 1) * sizeof(doublecomplex));

    for (int idx = 1; idx <= i__1; ++idx) {
        zx[idx].r = 1.0 + idx * 0.01;
        zx[idx].i = 0.5 - idx * 0.005;
    }
}