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
    // Trip count remains the same but each iteration performs more work
    for (i = size - 1; i--; ) {
        double diff = x - xa[i];
        double term1 = dd[i] * diff;
        double term2 = y * diff;
        y = term1 + term2 + (diff * diff * 0.5);
    }
}
