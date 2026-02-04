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
        size_t c = r; // RAW dependency: r used after definition
        // Introduce loop-carried dependence by making k depend on previous iteration indirectly
        if (p > 0) {
            k += r; // Additional use of r, reinforcing RAW
        }
    }
}
