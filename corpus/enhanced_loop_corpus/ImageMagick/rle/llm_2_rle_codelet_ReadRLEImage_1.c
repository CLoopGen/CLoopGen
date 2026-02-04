#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t number_planes;
extern ssize_t i;
extern unsigned char background_color[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse traversal
    for (i = (ssize_t)number_planes - 1; i >= 0; i--)
        background_color[i] = 0;
}
