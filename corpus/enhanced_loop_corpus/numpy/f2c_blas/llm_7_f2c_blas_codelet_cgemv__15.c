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
    integer local_offset = iy;
    for (i__ = 1; i__ <= i__1; ++i__) {
        y[local_offset].r = 0.F;
        y[local_offset].i = 0.F;
        local_offset += *incy;
    }
    iy = local_offset;
}
