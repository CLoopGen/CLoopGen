#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *y;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element first, then the odd indices)
    // This modifies the access pattern to be non-consecutive, improving potential for vectorization or cache line utilization
    i__ = 1;
    // Process even strides first
    for (; i__ <= i__1; i__ += 2) {
        y[i__] = 0.F;
    }
    // Reset and process odd strides
    for (i__ = 2; i__ <= i__1; i__ += 2) {
        y[i__] = 0.F;
    }
}
