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
    size_t step = 2;
    for (i = size - 1; i-- && i % step == 0;)
        y = dd[i] + (x - xa[i]) * y + (dd[i] * xa[i]) / (x + 1.0e-9); // Added multiplication and division
}
