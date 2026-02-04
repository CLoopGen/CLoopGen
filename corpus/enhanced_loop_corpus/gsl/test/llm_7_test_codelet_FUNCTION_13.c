#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t array[10] = {0};
    for (i = 0; i < 1027; i++) {
        // Create a loop-carried dependence: each iteration writes to array[i % 10]
        // which may be read in a later iteration with the same index.
        // This introduces a WAW and potentially WAR/RAW across iterations.
        array[i % 10] = array[i % 10] + 1;
    }
    // Final dummy use to prevent elimination
    i = array[0];
}
