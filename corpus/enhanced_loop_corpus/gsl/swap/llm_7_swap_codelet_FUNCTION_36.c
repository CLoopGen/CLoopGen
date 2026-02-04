#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t k = 0;
    size_t r = size1 > 0 ? 1 : 0;
    for (p = 0; p < size1; p++) {
        k += p;          // WAW dependency on k across iterations (loop-carried)
        size_t temp = k * 2;
        r = temp + 5;    // WAR/WAW: r is updated each iteration, no dependency on previous r value
        size_t c = p % 3; // No dependency on prior iterations (parallelizable)
    }
}
