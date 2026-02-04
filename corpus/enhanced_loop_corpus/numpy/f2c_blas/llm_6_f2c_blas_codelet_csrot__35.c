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
    integer local_ix = ix;
    integer local_iy = iy;
    
    singlecomplex temp_cx = cx[local_ix];
    singlecomplex temp_cy = cy[local_iy];

    q__2.r = *c__ * temp_cx.r; q__2.i = *c__ * temp_cx.i;
    q__3.r = *s * temp_cy.r; q__3.i = *s * temp_cy.i;
    ctemp.r = q__2.r + q__3.r; ctemp.i = q__2.i + q__3.i;

    q__2.r = *c__ * temp_cy.r; q__2.i = *c__ * temp_cy.i;
    q__3.r = *s * temp_cx.r; q__3.i = *s * temp_cx.i;
    q__1.r = q__2.r - q__3.r; q__1.i = q__2.i - q__3.i;

    cy[local_iy].r = q__1.r; cy[local_iy].i = q__1.i;
    cx[local_ix].r = ctemp.r; cx[local_ix].i = ctemp.i;

    ix += *incx;
    iy += *incy;
}
}
