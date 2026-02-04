#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = 0; p < size1; p++) {
        size_t k = p * 2;
        size_t r = k + 1;
        size_t c = r; // RAW dependency: r is read after being written
        // Introduces loop-carried dependence via cumulative use of p
        // Each iteration depends on the current value of p (induction variable)
    }
}
