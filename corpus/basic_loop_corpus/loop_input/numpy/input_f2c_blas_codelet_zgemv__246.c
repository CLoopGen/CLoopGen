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

doublecomplex *beta;
doublecomplex *y;
integer i__1;
integer i__2;
integer i__3;
doublecomplex z__1;
integer i__;

void init_vars() {
    i__1 = 10000000;  

    beta = (doublecomplex *)malloc(sizeof(doublecomplex));
    if (!beta) exit(1);
    beta->r = 1.5;
    beta->i = 0.8;

    y = (doublecomplex *)calloc(i__1 + 1, sizeof(doublecomplex));
    if (!y) exit(1);

    for (int idx = 1; idx <= i__1; ++idx) {
        y[idx].r = 0.1 * idx;
        y[idx].i = 0.05 * idx;
    }

    i__2 = 0;
    i__3 = 0;
    z__1.r = 0.0;
    z__1.i = 0.0;
    i__ = 0;
}