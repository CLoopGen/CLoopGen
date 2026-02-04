#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real psi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element, then handle remainder)
    integer stride = 2;
    integer j;
    for (j = 1; j <= i__1; j += stride) {
        psi += z__[j] * z__[j] / (delta[j] * work[j]);
    }
    // Handle any remaining element if i__1 is odd
    if (i__1 % 2 == 0 && i__1 >= 1) {
        psi += z__[i__1] * z__[i__1] / (delta[i__1] * work[i__1]);
    }
}
