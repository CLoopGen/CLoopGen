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
for (i__ = 0; i__ < i__1; ++i__) {
    int offset_x = (i__ << 2) % i__1; // Strided access with power-of-2 stride (modulo to stay in bounds)
    int offset_y = (i__ << 2) % i__1;
    zy[offset_y].r = zx[offset_x].r;
    zy[offset_y].i = zx[offset_x].i;
}
}
