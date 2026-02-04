#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t prev_extent = 256;
    for (extent = 256; extent < length; prev_extent = extent, extent = prev_extent * 2) {
        if (prev_extent == extent) break;
    }
}
