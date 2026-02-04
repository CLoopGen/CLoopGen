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
integer *incy;
integer i__1;
integer i__2;
integer i__3;
doublecomplex z__1;
integer i__;
integer iy;

void init_vars() {
    // Allocate and initialize beta
    beta = (doublecomplex*)malloc(sizeof(doublecomplex));
    beta->r = 1.5;
    beta->i = 0.5;

    // Set vector length to achieve ~0.01 seconds runtime
    // Assuming each iteration is a few cycles, aim for tens of millions of iterations
    i__1 = 16777216;  // 16M elements, typical size for ~0.01 sec on modern CPU

    // Allocate y array
    y = (doublecomplex*)malloc(i__1 * sizeof(doublecomplex));
    if (!y) exit(1);

    // Initialize y elements
    for (int j = 0; j < i__1; ++j) {
        y[j].r = (doublereal)(j % 128) / 128.0;
        y[j].i = (doublereal)((j + 16) % 128) / 128.0;
    }

    // Set incy: stride for index update
    incy = (integer*)malloc(sizeof(integer));
    *incy = 1;  // simple increment

    // Initialize loop index and pointer
    i__ = 1;
    iy = 0;  // base index into y array, zero-based for C array access

    // Initialize temporaries
    z__1.r = 0.0;
    z__1.i = 0.0;
    i__2 = 0;
    i__3 = 0;
}