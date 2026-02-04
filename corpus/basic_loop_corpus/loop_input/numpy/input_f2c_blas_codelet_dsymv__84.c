#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *beta;
doublereal *y;
integer i__1;
integer i__;

void init_vars() {
    i__1 = 10000000;  // Size to achieve ~0.01 sec runtime on modern CPU
    beta = (doublereal*)malloc(sizeof(doublereal));
    y = (doublereal*)malloc((i__1 + 1) * sizeof(doublereal));

    *beta = 2.5;
    for (int j = 1; j <= i__1; ++j) {
        y[j] = (doublereal)(j % 100);
    }
}