#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = 0; p < size1; p++) {
        size_t k = size1 - p;
        size_t r;
        size_t c;
        r = k * k; // Independent computation, no loop-carried dependencies
        c = k + 2; // All variables are local and redefined each iteration
        // Eliminated inter-iteration dependencies; fully parallelizable
    }
}
