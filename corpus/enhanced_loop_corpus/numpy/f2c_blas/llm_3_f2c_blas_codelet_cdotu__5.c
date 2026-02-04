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
// Consecutive memory access with precomputed base pointers
singlecomplex *base_cx = cx;
singlecomplex *base_cy = cy;
for (i__ = 0; i__ < i__1; ++i__) {
    singlecomplex temp;
    temp.r = base_cx[i__].r * base_cy[i__].r - base_cx[i__].i * base_cy[i__].i;
    temp.i = base_cx[i__].r * base_cy[i__].i + base_cx[i__].i * base_cy[i__].r;
    ctemp.r += temp.r;
    ctemp.i += temp.i;
}
}
