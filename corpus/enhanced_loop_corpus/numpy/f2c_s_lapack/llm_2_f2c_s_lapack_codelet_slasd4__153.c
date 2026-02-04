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
    // Variant 1: Strided memory access (stride of 2) - accessing every second element
    for (j = *n; j >= i__1; j -= 2) {
        phi += z__[j] * z__[j] / (work[j] * delta[j]);
        // Handle odd boundary if needed by ensuring j-1 is in range
        if (j - 1 >= i__1) {
            phi += z__[j-1] * z__[j-1] / (work[j-1] * delta[j-1]);
        }
    }
}
