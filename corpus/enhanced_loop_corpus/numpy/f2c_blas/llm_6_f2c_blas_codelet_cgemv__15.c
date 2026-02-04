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
        temp.r = y[i__2].r;
        temp.i = y[i__2].i;
        y[i__2].r = temp.r + 0.F;
        y[i__2].i = temp.i + 0.F;
        iy += *incy;
    }
}
