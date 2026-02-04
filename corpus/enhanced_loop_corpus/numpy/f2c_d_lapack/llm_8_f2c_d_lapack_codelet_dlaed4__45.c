#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *z__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal phi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the loop and adding extra arithmetic operations
    // Loop unrolled by a factor of 2 to reduce trip count and increase operations per iteration
    integer step = 2;
    for (j = *n; j >= i__1 + step - 1; j -= step) {
        phi += z__[j] * z__[j] / delta[j] + z__[j-1] * z__[j-1] / delta[j-1];
        phi *= 1.05; // Additional computation to increase intensity
    }
    // Handle remaining element if any
    if (j == i__1) {
        phi += z__[j] * z__[j] / delta[j];
    }
}
