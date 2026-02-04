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
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer ix;
extern integer iy;
extern singlecomplex ctemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    i__2 = ix;
    i__3 = iy;
    // Unroll the loop by processing two iterations per loop body to increase computational intensity
    if (i__ + 0 <= i__1) {
        q__2.r = cx[i__2].r * cy[i__3].r - cx[i__2].i * cy[i__3].i;
        q__2.i = cx[i__2].r * cy[i__3].i + cx[i__2].i * cy[i__3].r;
        ctemp.r += q__2.r;
        ctemp.i += q__2.i;
        integer ix_next = ix + *incx;
        integer iy_next = iy + *incy;
        if (i__ + 1 <= i__1) {
            i__2 = ix_next;
            i__3 = iy_next;
            q__2.r = cx[i__2].r * cy[i__3].r - cx[i__2].i * cy[i__3].i;
            q__2.i = cx[i__2].r * cy[i__3].i + cx[i__2].i * cy[i__3].r;
            ctemp.r += q__2.r;
            ctemp.i += q__2.i;
            ix = ix_next + *incx;
            iy = iy_next + *incy;
            ++i__;
        } else {
            ix = ix_next;
            iy = iy_next;
        }
    }
}
}
