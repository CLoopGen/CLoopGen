#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef double doublereal;
typedef int integer;

doublereal *dx;
integer *incx;
doublereal *dy;
integer *incy;
integer i__1;
integer i__;
integer ix;
integer iy;
doublereal dtemp;

static doublereal dx_data[131072];
static doublereal dy_data[131072];

void init_vars() {
    const int size = 131072;

    for (int i = 0; i < size; ++i) {
        dx_data[i] = (doublereal)(i + 1);
        dy_data[i] = (doublereal)(2 * (i + 1));
    }

    dx = dx_data;
    dy = dy_data;

    incx = (integer*)malloc(sizeof(integer));
    incy = (integer*)malloc(sizeof(integer));

    *incx = 1;
    *incy = 1;

    i__1 = 131072;
    i__ = 1;
    ix = 0;
    iy = 0;
    dtemp = 0.0;
}