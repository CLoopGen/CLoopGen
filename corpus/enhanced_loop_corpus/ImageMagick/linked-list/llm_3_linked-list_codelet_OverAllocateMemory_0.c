#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access pattern with forward iteration
    // Changed to increment by 1 starting from 256 to traverse each element consecutively
    for (extent = 256; extent < length; extent += 1) {
        // Simulated consecutive access, e.g., processing arr[extent] in order
        volatile size_t dummy = extent; // Prevent optimization
    }
}
