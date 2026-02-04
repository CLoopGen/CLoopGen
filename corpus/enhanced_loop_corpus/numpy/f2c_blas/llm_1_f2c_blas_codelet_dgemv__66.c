#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *y;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i__1 > 0) {
        i__ = 1;
        for (; i__ <= i__1; ++i__) {
            for (integer unroll = 0; unroll < 1; ++unroll) {
                y[iy] = 0.;
                iy += *incy;
            }
        }
    }
}
