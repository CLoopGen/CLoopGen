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
doublecomplex local_cx, local_cy;
for (i__ = 1; i__ <= i__1; ++i__) {
    i__2 = ix;
    i__3 = iy;
    local_cx = cx[i__2];
    local_cy = cy[i__3];
    z__2.r = *c__ * local_cx.r; z__2.i = *c__ * local_cx.i;
    z__3.r = *s * local_cy.r; z__3.i = *s * local_cy.i;
    ctemp.r = z__2.r + z__3.r; ctemp.i = z__2.i + z__3.i;
    z__2.r = *c__ * local_cy.r; z__2.i = *c__ * local_cy.i;
    z__3.r = *s * local_cx.r; z__3.i = *s * local_cx.i;
    z__1.r = z__2.r - z__3.r; z__1.i = z__2.i - z__3.i;
    cy[i__3].r = z__1.r; cy[i__3].i = z__1.i;
    cx[i__2].r = ctemp.r; cx[i__2].i = ctemp.i;
    ix += *incx;
    iy += *incy;
}
}
