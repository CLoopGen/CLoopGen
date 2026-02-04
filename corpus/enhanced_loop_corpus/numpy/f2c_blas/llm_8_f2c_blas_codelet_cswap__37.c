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
extern integer i__;
extern integer ix;
extern integer iy;
extern singlecomplex ctemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    i__2 = ix;
    ctemp.r = cx[i__2].r + cx[i__2].i;
    ctemp.i = cx[i__2].r - cx[i__2].i;
    i__3 = iy;
    real temp_r = cy[i__3].r * 0.5f;
    real temp_i = cy[i__3].i * 0.5f;
    cx[i__2].r = temp_r;
    cx[i__2].i = temp_i;
    i__2 = iy;
    cy[i__2].r = ctemp.r * 0.5f;
    cy[i__2].i = ctemp.i * 0.5f;
    ix += *incx;
    iy += *incy;
}
}
