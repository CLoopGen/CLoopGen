#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *beta;
extern doublereal *y;
extern integer *incy;
extern integer i__1;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations
    // Each iteration now performs multiple fused multiply-add operations to increase compute load
    for (i__ = 1; i__ <= i__1; ++i__) {
        doublereal temp = y[iy];
        temp = *beta * temp + *beta * temp;  // Double application: 2 multiplications and 1 addition
        temp = temp - *beta * 0.1 * temp;    // Additional modulation: more arithmetic
        y[iy] = temp;
        iy += *incy;
    }
}
