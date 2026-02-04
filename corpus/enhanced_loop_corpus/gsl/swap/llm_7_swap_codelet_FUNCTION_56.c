#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t k = 0;
    size_t r = 0;
    for (p = 0; p < size1; p++) {
        size_t temp = k + r;   // Introduces loop-carried dependency via k and r
        k = temp + p;          // Update k based on previous values — loop-carried RAW
        r = r + 1;             // Accumulator-style loop-carried dependency on r
        size_t c = p * p;      // Independent computation, no loop-carried dependency
    }
}
