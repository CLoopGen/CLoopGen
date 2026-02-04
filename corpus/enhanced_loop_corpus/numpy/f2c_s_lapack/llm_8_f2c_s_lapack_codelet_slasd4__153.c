#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *z__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real phi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the loop and increasing arithmetic operations
    // Loop unrolled by a factor of 2 to reduce loop overhead and increase FLOPs per iteration
    integer decrement = 2;
    for (j = *n; j >= i__1 + decrement - 1; j -= decrement) {
        phi += z__[j] * z__[j] / (work[j] * delta[j]);
        phi += z__[j-1] * z__[j-1] / (work[j-1] * delta[j-1]);
    }
    // Handle remaining iteration if loop count is odd
    if (j == i__1) {
        phi += z__[j] * z__[j] / (work[j] * delta[j]);
    }
}
