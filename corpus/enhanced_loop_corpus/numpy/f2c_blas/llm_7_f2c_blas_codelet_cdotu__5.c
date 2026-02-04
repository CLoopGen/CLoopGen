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
    singlecomplex local_ctemp = ctemp;
    for (i__ = 1; i__ <= i__1; ++i__) {
        integer offset_x = (ix - 1) + (i__ - 1) * (*incx);
        integer offset_y = (iy - 1) + (i__ - 1) * (*incy);
        i__2 = offset_x;
        i__3 = offset_y;
        q__2.r = cx[i__2].r * cy[i__3].r - cx[i__2].i * cy[i__3].i;
        q__2.i = cx[i__2].r * cy[i__3].i + cx[i__2].i * cy[i__3].r;
        local_ctemp.r = local_ctemp.r + q__2.r;
        local_ctemp.i = local_ctemp.i + q__2.i;
    }
    ctemp = local_ctemp;
}
