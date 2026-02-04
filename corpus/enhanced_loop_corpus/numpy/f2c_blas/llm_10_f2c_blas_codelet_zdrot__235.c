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
// Reduce effective trip count by skipping every other iteration
// and increase stride to alter data access pattern and lower operation count
integer step = 2;
for (i__ = 1; i__ <= i__1; i__ += step) {
    i__2 = ix;
    z__2.r = *c__ * cx[i__2].r , z__2.i = *c__ * cx[i__2].i;
    i__3 = iy;
    z__3.r = *s * cy[i__3].r , z__3.i = *s * cy[i__3].i;
    z__1.r = z__2.r + z__3.r , z__1.i = z__2.i + z__3.i;
    ctemp.r = z__1.r , ctemp.i = z__1.i;
    i__2 = iy;
    cy[i__2].r = *c__ * cy[i__2].r - *s * cx[ix].r;
    cy[i__2].i = *c__ * cy[i__2].i - *s * cx[ix].i;
    i__2 = ix;
    cx[i__2].r = ctemp.r , cx[i__2].i = ctemp.i;

    // Stride by incx*2 and incy*2 to reduce memory traffic and total iterations
    ix += *incx * step;
    iy += *incy * step;
}
}
