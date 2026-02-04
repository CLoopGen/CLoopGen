#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

static doublereal dx_data[65536];
static doublereal dy_data[65536];

void init_vars() {
    const int size = 65536;
    
    for (int i = 0; i < size; ++i) {
        dx_data[i] = (doublereal)(i % 1234);
        dy_data[i] = (doublereal)(i % 5678);
    }

    dx = dx_data;
    dy = dy_data;

    incx = (integer*)malloc(sizeof(integer));
    incy = (integer*)malloc(sizeof(integer));
    
    *incx = 1;
    *incy = 1;

    i__1 = 65536;
    ix = 0;
    iy = 0;
    dtemp = 0.0;

    i__ = 0;
}