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
extern real dphi;
extern real temp;
extern real erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    integer step = 2;
    for (j = *n; j >= i__1 + step - 1; j -= step) {
        // Unroll two iterations
        temp = z__[j] / (work[j] * delta[j]);
        phi += z__[j] * temp;
        dphi += temp * temp;
        erretm += phi;

        temp = z__[j-1] / (work[j-1] * delta[j-1]);
        phi += z__[j-1] * temp;
        dphi += temp * temp;
        erretm += phi;
    }
    // Handle remaining iteration if needed
    if (j == i__1) {
        temp = z__[j] / (work[j] * delta[j]);
        phi += z__[j] * temp;
        dphi += temp * temp;
        erretm += phi;
    }
}
