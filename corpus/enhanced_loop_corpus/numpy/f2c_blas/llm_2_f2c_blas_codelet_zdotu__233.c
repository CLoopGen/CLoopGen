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

extern doublecomplex *zx;
extern integer *incx;
extern doublecomplex *zy;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern integer i__;
extern integer ix;
extern integer iy;
extern doublecomplex ztemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 0; i__ < i__1; ++i__) {
    integer index_x = i__ * (*incx);
    integer index_y = i__ * (*incy);
    z__2.r = zx[index_x].r * zy[index_y].r - zx[index_x].i * zy[index_y].i;
    z__2.i = zx[index_x].r * zy[index_y].i + zx[index_x].i * zy[index_y].r;
    z__1.r = ztemp.r + z__2.r;
    z__1.i = ztemp.i + z__2.i;
    ztemp.r = z__1.r;
    ztemp.i = z__1.i;
}
}
