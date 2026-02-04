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

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    i__2 = iy;
    i__3 = ix;
    cy[i__2].r = cx[i__3].r , cy[i__2].i = cx[i__3].i;
    ix += *incx;
    iy += *incy;
}

}
