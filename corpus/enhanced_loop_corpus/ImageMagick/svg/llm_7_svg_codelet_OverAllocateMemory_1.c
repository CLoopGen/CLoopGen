#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t prev_extent = 256;
    for (extent = 256; extent < length; extent = prev_extent) {
        prev_extent = extent * 2;
        if (prev_extent <= extent) break; // Prevent overflow or infinite loop
    }
    extent = prev_extent;
}
