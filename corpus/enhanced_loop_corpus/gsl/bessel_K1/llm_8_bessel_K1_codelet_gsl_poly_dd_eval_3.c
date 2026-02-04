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
    for (i = size - 1; i--;)
        y = dd[i] + (x - xa[i]) * y + (dd[i] * xa[i]) / (x + 1.0e-9); // Avoid division by zero
}
