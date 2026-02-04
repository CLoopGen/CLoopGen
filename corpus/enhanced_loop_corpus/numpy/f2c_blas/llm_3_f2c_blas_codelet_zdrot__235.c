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

extern doublecomplex *cx;
extern integer *incx;
extern doublecomplex *cy;
extern integer *incy;
extern doublereal *c__;
extern doublereal *s;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern doublecomplex z__3;
extern integer i__;
extern integer ix;
extern integer iy;
extern doublecomplex ctemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 0; i__ < i__1; ++i__) {
    int offset_x = ix + i__ * (*incx);
    int offset_y = iy + i__ * (*incy);
    
    z__2.r = *c__ * cx[offset_x].r; z__2.i = *c__ * cx[offset_x].i;
    z__3.r = *s * cy[offset_y].r; z__3.i = *s * cy[offset_y].i;
    z__1.r = z__2.r + z__3.r; z__1.i = z__2.i + z__3.i;
    ctemp.r = z__1.r; ctemp.i = z__1.i;

    z__2.r = *c__ * cy[offset_y].r; z__2.i = *c__ * cy[offset_y].i;
    z__3.r = *s * cx[offset_x].r; z__3.i = *s * cx[offset_x].i;
    z__1.r = z__2.r - z__3.r; z__1.i = z__2.i - z__3.i;
    cy[offset_y].r = z__1.r; cy[offset_y].i = z__1.i;

    cx[offset_x].r = ctemp.r; cx[offset_x].i = ctemp.i;
}
}
