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
doublereal *c__;
doublereal *s;
integer i__1;
integer i__;
integer ix;
integer iy;
doublereal dtemp;

#define DATA_SIZE (64 << 20) / sizeof(doublereal)

void init_vars() {
    dx = (doublereal*)calloc(DATA_SIZE, sizeof(doublereal));
    dy = (doublereal*)calloc(DATA_SIZE, sizeof(doublereal));
    incx = (integer*)malloc(sizeof(integer));
    incy = (integer*)malloc(sizeof(integer));
    c__ = (doublereal*)malloc(sizeof(doublereal));
    s = (doublereal*)malloc(sizeof(doublereal));

    *incx = 1;
    *incy = 1;
    *c__ = 0.866; 
    *s = 0.5;

    for (size_t i = 0; i < DATA_SIZE; ++i) {
        dx[i] = (doublereal)(i + 1);
        dy[i] = (doublereal)(-(i + 1));
    }

    i__1 = DATA_SIZE - 1;
    i__ = 0;
    ix = 0;
    iy = 0;
    dtemp = 0.0;
}