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

extern singlecomplex *cx;
extern integer *incx;
extern singlecomplex *cy;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer ix;
extern integer iy;
extern singlecomplex ctemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    i__2 = ix;
    i__3 = iy;
    if (cx[i__2].r != 0.0f || cy[i__3].r != 0.0f) {
        q__2.r = cx[i__2].r * cy[i__3].r - cx[i__2].i * cy[i__3].i , q__2.i = cx[i__2].r * cy[i__3].i + cx[i__2].i * cy[i__3].r;
        q__1.r = ctemp.r + q__2.r , q__1.i = ctemp.i + q__2.i;
        ctemp.r = q__1.r , ctemp.i = q__1.i;
    }
    ix += *incx;
    iy += *incy;
}
}
