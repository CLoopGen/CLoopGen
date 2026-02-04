#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

extern singlecomplex *ca;
extern singlecomplex *cx;
extern integer *incx;
extern singlecomplex *cy;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer ix;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 0; i__ < i__1; ++i__) {
    integer index_x = i__ * (*incx);
    integer index_y = i__ * (*incy);
    singlecomplex temp;
    temp.r = ca->r * cx[index_x].r - ca->i * cx[index_x].i;
    temp.i = ca->r * cx[index_x].i + ca->i * cx[index_x].r;
    cy[index_y].r += temp.r;
    cy[index_y].i += temp.i;
}
}
