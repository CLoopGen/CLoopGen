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
doublecomplex scale;
scale.r = *da;
scale.i = 0.0;
for (i__ = 1; i__ <= i__1; ++i__) {
    zx[i__].r = scale.r * zx[i__].r;
    zx[i__].i = scale.r * zx[i__].i;
}
}
