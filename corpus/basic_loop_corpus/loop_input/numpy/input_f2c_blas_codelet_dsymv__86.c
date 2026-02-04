#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *beta;
doublereal *y;
integer *incy;
integer i__1;
integer i__;
integer iy;

void init_vars() {
    // Allocate and initialize beta
    beta = (doublereal*)malloc(sizeof(doublereal));
    *beta = 2.5;

    // Set vector size to achieve ~0.01 sec runtime
    // Assuming moderate CPU speed and simple arithmetic, aim for ~10-50 million elements
    i__1 = 20000000;  // 20 million iterations

    // Allocate y array: size must accommodate index accesses via iy
    y = (doublereal*)calloc(i__1, sizeof(doublereal));
    if (!y) exit(1);

    // Initialize incy
    incy = (integer*)malloc(sizeof(integer));
    *incy = 1;

    // Initialize loop index
    i__ = 1;

    // Initialize pointer index (iy is 1-based)
    iy = 0;  // so that first access is y[0] when i__=1
}