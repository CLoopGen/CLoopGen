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

static doublereal dx_data[65536];
static doublereal dy_data[65536];

void init_vars() {
    const int array_size = 65536;
    
    dx = dx_data;
    dy = dy_data;
    incx = (integer*)malloc(sizeof(integer));
    incy = (integer*)malloc(sizeof(integer));
    
    *incx = 1;
    *incy = 1;
    
    i__1 = array_size - 1;
    i__ = 1;
    ix = 0;
    iy = 0;
}