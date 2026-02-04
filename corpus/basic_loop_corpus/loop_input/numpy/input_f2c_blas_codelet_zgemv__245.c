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

integer i__1;
integer i__2;
integer i__;
doublecomplex *y;

void init_vars() {
    i__1 = 10000000; // Adjusted to achieve ~0.01 seconds runtime
    i__2 = 0;
    i__ = 0;

    y = (doublecomplex*)calloc((i__1 + 1), sizeof(doublecomplex));
    if (!y) {
        exit(1);
    }
}