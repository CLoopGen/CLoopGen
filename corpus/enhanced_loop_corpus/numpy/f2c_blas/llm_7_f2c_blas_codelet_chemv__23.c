#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

extern singlecomplex *y;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
singlecomplex temp;
for (i__ = 1; i__ <= i__1; ++i__) {
    i__2 = iy;
    temp.r = y[i__2].r + 0.5F;
    temp.i = y[i__2].i - 0.5F;
    y[i__2].r = temp.r;
    y[i__2].i = temp.i;
    iy += *incy;
}
}
