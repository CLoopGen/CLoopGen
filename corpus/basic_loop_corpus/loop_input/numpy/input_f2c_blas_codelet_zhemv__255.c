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

doublecomplex *y;
integer *incy;
integer i__1;
integer i__2;
integer i__;
integer iy;

void init_vars() {
    i__1 = 10000000;  // 10 million iterations for ~0.01s runtime
    incy = (integer*)malloc(sizeof(integer));
    *incy = 1;
    y = (doublecomplex*)calloc(i__1, sizeof(doublecomplex));
    iy = 0;
    i__ = 0;
    i__2 = 0;
}