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
        size_t temp = k + r;     // RAW: depends on previous iterations (loop-carried)
        r = k;                   // WAR: r written after being read indirectly via temp
        k = temp;                // WAW: k is updated, carrying value to next iteration
        size_t c = p + 1;        // Independent of loop-carried dependencies
    }
}
