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
    doublecomplex local_ztemp = ztemp;
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = ix;
        i__3 = iy;
        z__2.r = zx[i__2].r * zy[i__3].r - zx[i__2].i * zy[i__3].i;
        z__2.i = zx[i__2].r * zy[i__3].i + zx[i__2].i * zy[i__3].r;
        local_ztemp.r += z__2.r;
        local_ztemp.i += z__2.i;
        ix += *incx;
        iy += *incy;
    }
    ztemp = local_ztemp;
}
