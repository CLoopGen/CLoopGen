#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access with local array
    // Using a locally declared array to demonstrate sequential writes
    double buffer[1024]; // Assume width <= 1024
    for (int i = 0; i < width; i++) {
        buffer[i] = (double)(i + 1);
    }
}
