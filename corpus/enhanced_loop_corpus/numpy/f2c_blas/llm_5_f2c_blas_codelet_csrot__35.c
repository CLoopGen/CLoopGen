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
    singlecomplex temp_cx, temp_cy;
    i__2 = ix;
    temp_cx.r = cx[i__2].r; temp_cx.i = cx[i__2].i;
    i__3 = iy;
    temp_cy.r = cy[i__3].r; temp_cy.i = cy[i__3].i;

    if (*c__ > 0.5f) {
        q__1.r = *c__ * temp_cx.r + *s * temp_cy.r;
        q__1.i = *c__ * temp_cx.i + *s * temp_cy.i;
        ctemp = q__1;

        q__1.r = *c__ * temp_cy.r - *s * temp_cx.r;
        q__1.i = *c__ * temp_cy.i - *s * temp_cx.i;
        i__2 = iy;
        cy[i__2].r = q__1.r; cy[i__2].i = q__1.i;
    } else {
        q__1.r = *c__ * temp_cx.r - *s * temp_cy.r;
        q__1.i = *c__ * temp_cx.i - *s * temp_cy.i;
        ctemp = q__1;

        q__1.r = *c__ * temp_cy.r + *s * temp_cx.r;
        q__1.i = *c__ * temp_cy.i + *s * temp_cx.i;
        i__2 = iy;
        cy[i__2].r = q__1.r; cy[i__2].i = q__1.i;
    }

    i__2 = ix;
    cx[i__2].r = ctemp.r; cx[i__2].i = ctemp.i;

    ix += *incx;
    iy += *incy;
}
}
