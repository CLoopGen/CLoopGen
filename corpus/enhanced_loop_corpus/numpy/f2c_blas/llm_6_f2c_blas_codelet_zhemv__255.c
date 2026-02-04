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

extern doublecomplex *y;
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer temp_r = 0, temp_i = 0;
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = iy;
        y[i__2].r = temp_r;
        y[i__2].i = temp_i;
        temp_r += *incy;
        temp_i += *incy;
        iy += *incy;
    }
}
