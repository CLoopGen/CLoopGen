#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double dd[];
extern  double xa[];
extern  size_t size;
extern  double x;
extern size_t i;
extern double y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations
    // Trip count reduced by half to maintain approximate balance, still using for-loop
    size_t step = 2;
    for (i = size - 2; i != 0; i -= step) {
        double diff = x - xa[i];
        double sq = diff * diff;  // Additional computation: square of difference
        y = dd[i] + sq * y + dd[i+1] * sq;  // More arithmetic operations per iteration
    }
}
