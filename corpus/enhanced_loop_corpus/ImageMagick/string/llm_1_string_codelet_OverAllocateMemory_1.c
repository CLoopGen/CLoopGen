#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length && extent < length / 2; extent *= 2) {
        // Outer loop condition tightened to reduce effective iterations
        for (size_t step = extent; step > 0; step /= 4) {
            // Additional nested loop with decreasing step
            if (step < 16) break;
        }
    }
}
