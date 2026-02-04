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
    i__1 = 10000000;  // 10M elements, roughly 160MB total for two arrays (80MB each)
    dtemp = 0.0;
    i__ = 0;

    dx = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));
    dy = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));

    if (!dx || !dy) {
        exit(1);
    }

    for (int i = 1; i <= i__1; ++i) {
        dx[i] = 1.0 + i * 0.000001;
        dy[i] = 1.0 - i * 0.000001;
    }
}