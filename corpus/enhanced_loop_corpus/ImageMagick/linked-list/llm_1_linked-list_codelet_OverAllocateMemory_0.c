#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (extent < length) {
        for (extent = 256; extent < length && extent < 1024; extent *= 2) {
            // Original loop condition refined with upper bound
        }
    }
    // Outer conditional reduces effective loop depth in some cases
}
