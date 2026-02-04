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
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    doublecomplex temp = zx[i__];
    i__2 = i__;
    z__2.r = *da , z__2.i = 0.;
    z__1.r = z__2.r * temp.r - z__2.i * temp.i;
    z__1.i = z__2.r * temp.i + z__2.i * temp.r;
    zx[i__2].r = z__1.r;
    zx[i__2].i = z__1.i;
}
}
