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

extern singlecomplex *ca;
extern singlecomplex *cx;
extern integer *incx;
extern singlecomplex *cy;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer ix;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    i__2 = iy;
    i__3 = iy;
    i__4 = ix;
    // Unroll the loop by a factor of 2 to increase computational intensity
    if (i__ + 1 <= i__1) {
        // First iteration (current i__)
        q__2.r = ca->r * cx[i__4].r - ca->i * cx[i__4].i;
        q__2.i = ca->r * cx[i__4].i + ca->i * cx[i__4].r;
        q__1.r = cy[i__3].r + q__2.r;
        q__1.i = cy[i__3].i + q__2.i;
        cy[i__2].r = q__1.r;
        cy[i__2].i = q__1.i;

        // Second iteration (i__+1)
        integer ix1 = ix + *incx;
        integer iy1 = iy + *incy;
        i__2 = iy1;
        i__3 = iy1;
        i__4 = ix1;
        singlecomplex temp;
        temp.r = ca->r * cx[i__4].r - ca->i * cx[i__4].i;
        temp.i = ca->r * cx[i__4].i + ca->i * cx[i__4].r;
        q__1.r = cy[i__3].r + temp.r;
        q__1.i = cy[i__3].i + temp.i;
        cy[i__2].r = q__1.r;
        cy[i__2].i = q__1.i;

        ++i__;
        ix = ix1 + *incx;
        iy = iy1 + *incy;
    } else {
        // Handle last element if trip count is odd
        q__2.r = ca->r * cx[i__4].r - ca->i * cx[i__4].i;
        q__2.i = ca->r * cx[i__4].i + ca->i * cx[i__4].r;
        q__1.r = cy[i__3].r + q__2.r;
        q__1.i = cy[i__3].i + q__2.i;
        cy[i__2].r = q__1.r;
        cy[i__2].i = q__1.i;
        ix += *incx;
        iy += *incy;
    }
}
}
