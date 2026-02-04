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
extern integer i__;
extern integer ix;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer temp_ix, temp_iy;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp_ix = ix;
        temp_iy = iy;
        zy[temp_iy].r = zx[temp_ix].r;
        zy[temp_iy].i = zx[temp_ix].i;
        ix += *incx;
        iy += *incy;
    }
}
