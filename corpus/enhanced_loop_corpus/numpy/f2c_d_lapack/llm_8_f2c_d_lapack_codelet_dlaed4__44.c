#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal psi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled accumulation
    // Trip count remains the same, but each iteration performs more work (squaring and inverse computation)
    doublereal temp1, temp2;
    integer j3;
    for (j = 1; j <= i__1 - 3; j += 4) {
        temp1 = z__[j] * z__[j];
        psi += temp1 / delta[j] + temp1 * temp1;  // Additional squaring term increases FLOPs

        temp1 = z__[j+1] * z__[j+1];
        psi += temp1 / delta[j+1] + temp1 * temp1;

        temp1 = z__[j+2] * z__[j+2];
        psi += temp1 / delta[j+2] + temp1 * temp1;

        temp1 = z__[j+3] * z__[j+3];
        psi += temp1 / delta[j+3] + temp1 * temp1;
    }
    // Handle remainder
    for (j3 = j; j3 <= i__1; ++j3) {
        doublereal t = z__[j3] * z__[j3];
        psi += t / delta[j3] + t * t;
    }
}
