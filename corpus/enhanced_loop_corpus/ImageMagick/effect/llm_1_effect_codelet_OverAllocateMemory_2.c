#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length && extent < 65536; extent *= 2)
        for (size_t step = extent / 2; step > 0; step /= 2) {
            // Add a nested loop that performs reduction-style iteration
            volatile size_t dummy = step; // Avoid optimization
        }
}
