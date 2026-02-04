#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *d__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real temp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This variant accesses every second element in the arrays, forward traversal
    integer stride = 2;
    for (j = 1; j <= i__1; j += stride) {
        if (j <= i__1) {
            work[j] = d__[j] + d__[*n] + temp1;
            delta[j] = d__[j] - d__[*n] - temp1;
        }
    }
}
