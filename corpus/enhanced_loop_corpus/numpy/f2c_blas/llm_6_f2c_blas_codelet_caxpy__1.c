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
    singlecomplex temp;
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = iy;
        i__3 = iy;
        i__4 = ix;
        // Introduce temporary variable to modify WAW and WAR dependencies
        // This removes direct write-after-write on q__1 and breaks some loop-carried dependencies
        q__2.r = ca->r * cx[i__4].r - ca->i * cx[i__4].i;
        q__2.i = ca->r * cx[i__4].i + ca->i * cx[i__4].r;
        temp.r = cy[i__3].r + q__2.r;
        temp.i = cy[i__3].i + q__2.i;
        cy[i__2].r = temp.r;
        cy[i__2].i = temp.i;
        ix += *incx;
        iy += *incy;
    }
}
