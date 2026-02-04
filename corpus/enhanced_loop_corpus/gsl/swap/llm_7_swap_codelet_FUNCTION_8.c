#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_array[1024]; // Local storage to enable reordering
    for (p = 0; p < size1 && p < 1024; p++) {
        size_t k = p + 10;
        temp_array[p] = k; // Write with no immediate use — eliminate premature RAW
    }
    for (p = 0; p < size1 && p < 1024; p++) {
        size_t n = temp_array[p] * 2; // Use value in a separate loop — break loop-carried dependency
        temp_array[p] = n; // WAW on same array but independent across iterations now
    }
}
