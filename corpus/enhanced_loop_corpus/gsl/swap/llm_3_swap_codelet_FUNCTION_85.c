#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access pattern with reversed inner loop order
    // Ensures consecutive traversal by starting from a base and going forward without gaps
    for (i = 0; i < size1; i++) {
        size_t base = i + 1;
        if (base < size2) {
            for (j = base; j < size2; j++) {
                // Access pattern is now strictly consecutive from base to size2
            }
        }
    }
}
