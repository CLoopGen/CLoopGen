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
for (i__ = 1; i__ <= i__1; ++i__) {
    i__2 = ix;
    z__2.r = *c__ * cx[i__2].r , z__2.i = *c__ * cx[i__2].i;
    i__3 = iy;
    z__3.r = *s * cy[i__3].r , z__3.i = *s * cy[i__3].i;
    z__1.r = z__2.r + z__3.r , z__1.i = z__2.i + z__3.i;
    ctemp.r = z__1.r , ctemp.i = z__1.i;
    i__2 = iy;
    i__3 = iy;
    z__2.r = *c__ * cy[i__3].r , z__2.i = *c__ * cy[i__3].i;
    i__4 = ix;
    z__3.r = *s * cx[i__4].r , z__3.i = *s * cx[i__4].i;
    z__1.r = z__2.r - z__3.r , z__1.i = z__2.i - z__3.i;
    cy[i__2].r = z__1.r , cy[i__2].i = z__1.i;
    i__2 = ix;
    cx[i__2].r = ctemp.r , cx[i__2].i = ctemp.i;
    ix += *incx;
    iy += *incy;

    // Additional computational workload: simulate higher arithmetic intensity
    // Introduce auxiliary complex operations without changing control flow
    doublecomplex temp1, temp2, temp3;
    temp1.r = cx[i__2].r + cy[i__2].r;
    temp1.i = cx[i__2].i + cy[i__2].i;
    temp2.r = *c__ * temp1.r - *s * temp1.i;
    temp2.i = *s * temp1.r + *c__ * temp1.i;
    temp3.r = temp2.r * temp2.r - temp2.i * temp2.i;
    temp3.i = 2.0 * temp2.r * temp2.i;
    cx[i__2].r += temp3.r;
    cx[i__2].i += temp3.i;
}
}
