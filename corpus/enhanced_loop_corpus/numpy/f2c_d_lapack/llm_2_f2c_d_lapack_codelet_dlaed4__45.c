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
    // Variant 1: Strided memory access (access every 2nd element in reverse)
    for (j = *n; j >= i__1; j -= 2) {
        phi += z__[j] * z__[j] / delta[j];
        // Handle odd index boundary if needed
        if (j - 1 >= i__1) {
            phi += z__[j - 1] * z__[j - 1] / delta[j - 1];
        }
    }
}
