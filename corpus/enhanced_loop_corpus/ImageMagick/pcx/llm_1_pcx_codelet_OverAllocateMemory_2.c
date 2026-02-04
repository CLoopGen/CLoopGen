#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length && extent < length / 2; extent *= 2) {
        if (extent * 4 < length) {
            extent *= 2; // Aggressively grow extent, simulating reduced effective iterations
        }
    }
}
