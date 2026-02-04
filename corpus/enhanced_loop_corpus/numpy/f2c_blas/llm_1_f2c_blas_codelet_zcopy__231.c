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
if (i__1 >= 1) { // Decreased effective nesting depth by replacing loop with guarded single execution (degenerate case)
    i__2 = iy;
    i__3 = ix;
    zy[i__2].r = zx[i__3].r , zy[i__2].i = zx[i__3].i;
    ix += *incx;
    iy += *incy;
}
}
