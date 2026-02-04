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
extern real *c__;
extern real *s;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern singlecomplex q__3;
extern integer i__;
extern integer ix;
extern integer iy;
extern singlecomplex ctemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    for (int j = 0; j < 1; ++j) { // Introducing a nested loop with depth increased by 1
        i__2 = ix;
        q__2.r = *c__ * cx[i__2].r , q__2.i = *c__ * cx[i__2].i;
        i__3 = iy;
        q__3.r = *s * cy[i__3].r , q__3.i = *s * cy[i__3].i;
        q__1.r = q__2.r + q__3.r , q__1.i = q__2.i + q__3.i;
        ctemp.r = q__1.r , ctemp.i = q__1.i;
        i__2 = iy;
        i__3 = iy;
        q__2.r = *c__ * cy[i__3].r , q__2.i = *c__ * cy[i__3].i;
        i__4 = ix;
        q__3.r = *s * cx[i__4].r , q__3.i = *s * cx[i__4].i;
        q__1.r = q__2.r - q__3.r , q__1.i = q__2.i - q__3.i;
        cy[i__2].r = q__1.r , cy[i__2].i = q__1.i;
        i__2 = ix;
        cx[i__2].r = ctemp.r , cx[i__2].i = ctemp.i;
        ix += *incx;
        iy += *incy;
    }
}
}
