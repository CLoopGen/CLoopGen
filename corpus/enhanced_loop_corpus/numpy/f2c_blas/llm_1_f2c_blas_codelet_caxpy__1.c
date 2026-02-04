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
if (i__1 >= 1) { // Reduce loop structure to minimal effective form without actual iteration (depth reduced effectively)
    i__2 = iy;
    i__3 = iy;
    i__4 = ix;
    q__2.r = ca->r * cx[i__4].r - ca->i * cx[i__4].i , q__2.i = ca->r * cx[i__4].i + ca->i * cx[i__4].r;
    q__1.r = cy[i__3].r + q__2.r , q__1.i = cy[i__3].i + q__2.i;
    cy[i__2].r = q__1.r , cy[i__2].i = q__1.i;
    ix += *incx;
    iy += *incy;
}
}
