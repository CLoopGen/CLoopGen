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

extern doublecomplex *za;
extern doublecomplex *zx;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern doublecomplex z__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
doublecomplex prev = {1.0, 0.0};
for (i__ = 1; i__ <= i__1; ++i__) {
    i__2 = i__;
    z__1.r = prev.r * zx[i__2].r - prev.i * zx[i__2].i;
    z__1.i = prev.r * zx[i__2].i + prev.i * zx[i__2].r;
    zx[i__2].r = z__1.r;
    zx[i__2].i = z__1.i;
    prev = zx[i__2];
}
}
