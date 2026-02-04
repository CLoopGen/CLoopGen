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
    // Trip count reduced by half to maintain similar execution time but higher ops per iteration
    y = 1.0; // Initialize y to avoid undefined behavior
    for (i = (size - 1) / 2; i--; ) {
        double diff = x - xa[i];
        double sq = diff * diff;
        double term = dd[i] + sq * y;
        y = term + 0.5 * sq * term; // Additional computation: nonlinear feedback
    }
}
