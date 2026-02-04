#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int max;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every element with a stride of 1 but in reverse order)
    // This variant maintains the same logic but emphasizes strided traversal by explicitly indexing with arithmetic
    unsigned int index;
    for (index = 15; index >= 1; index--) {
        if (count[15 - index] != 0) {  // Reverse indexing pattern: accesses count[0], count[14], count[1], ...
            max = 15 - index;
            break;
        }
    }
}
