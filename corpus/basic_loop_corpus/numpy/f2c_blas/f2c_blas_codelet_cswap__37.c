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
    ctemp.r = cx[i__2].r , ctemp.i = cx[i__2].i;
    i__2 = ix;
    i__3 = iy;
    cx[i__2].r = cy[i__3].r , cx[i__2].i = cy[i__3].i;
    i__2 = iy;
    cy[i__2].r = ctemp.r , cy[i__2].i = ctemp.i;
    ix += *incx;
    iy += *incy;
}

}
