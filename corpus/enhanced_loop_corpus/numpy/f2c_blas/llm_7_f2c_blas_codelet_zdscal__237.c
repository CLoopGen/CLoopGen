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

extern doublereal *da;
extern doublecomplex *zx;
extern integer *incx;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern integer i__;
extern integer ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer local_ix = ix;
for (i__ = 1; i__ <= i__1; ++i__) {
    z__2.r = *da , z__2.i = 0.;
    z__1.r = z__2.r * zx[local_ix].r - z__2.i * zx[local_ix].i , z__1.i = z__2.r * zx[local_ix].i + z__2.i * zx[local_ix].r;
    zx[local_ix].r = z__1.r , zx[local_ix].i = z__1.i;
    local_ix += *incx;
}
ix = local_ix;
}
