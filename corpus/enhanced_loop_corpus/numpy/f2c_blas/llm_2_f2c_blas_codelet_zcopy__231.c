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
    int index_y = i__ * (*incy);
    int index_x = i__ * (*incx);
    zy[index_y].r = zx[index_x].r;
    zy[index_y].i = zx[index_x].i;
}
}
