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
    integer temp_ix = ix;
    integer temp_iy = iy;
    doublecomplex cx_val = cx[temp_ix];
    doublecomplex cy_val = cy[temp_iy];
    z__2.r = *c__ * cx_val.r; z__2.i = *c__ * cx_val.i;
    z__3.r = *s * cy_val.r; z__3.i = *s * cy_val.i;
    ctemp.r = z__2.r + z__3.r; ctemp.i = z__2.i + z__3.i;
    z__2.r = *c__ * cy_val.r; z__2.i = *c__ * cy_val.i;
    z__3.r = *s * cx_val.r; z__3.i = *s * cx_val.i;
    z__1.r = z__2.r - z__3.r; z__1.i = z__2.i - z__3.i;
    cy[temp_iy].r = z__1.r; cy[temp_iy].i = z__1.i;
    cx[temp_ix].r = ctemp.r; cx[temp_ix].i = ctemp.i;
    ix += *incx;
    iy += *incy;
}
}
