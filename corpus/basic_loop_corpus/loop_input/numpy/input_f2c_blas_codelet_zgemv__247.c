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

static doublecomplex y_buffer[65536];
static integer incy_value;

void init_vars() {
    i__1 = 65536;
    iy = 0;
    incy_value = 1;
    incy = &incy_value;
    y = y_buffer;
    i__ = 0;
    i__2 = 0;
}