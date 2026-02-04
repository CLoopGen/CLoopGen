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
    // Variant 1: Consecutive memory access by removing strided indexing and accessing y in sequential order
    // Assuming incy value is positive and we can rewrite the access pattern to be consecutive
    integer base_index = iy;
    for (i__ = 1; i__ <= i__1; ++i__) {
        y[base_index + (i__ - 1)] = 0.;
    }
}
