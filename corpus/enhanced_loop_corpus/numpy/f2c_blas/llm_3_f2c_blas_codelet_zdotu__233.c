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
integer base_ix = ix;
integer base_iy = iy;
for (i__ = 0; i__ < i__1; ++i__) {
    integer offset_x = (i__ & 3) * (*incx); // Strided access with modulo-like pattern (stride of up to 4)
    integer offset_y = (i__ & 3) * (*incy);
    z__2.r = zx[base_ix + offset_x].r * zy[base_iy + offset_y].r - zx[base_ix + offset_x].i * zy[base_iy + offset_y].i;
    z__2.i = zx[base_ix + offset_x].r * zy[base_iy + offset_y].i + zx[base_ix + offset_x].i * zy[base_iy + offset_y].r;
    z__1.r = ztemp.r + z__2.r;
    z__1.i = ztemp.i + z__2.i;
    ztemp.r = z__1.r;
    ztemp.i = z__1.i;
}
}
