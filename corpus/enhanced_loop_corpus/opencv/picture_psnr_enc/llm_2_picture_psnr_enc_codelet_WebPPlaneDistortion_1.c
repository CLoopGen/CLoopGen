#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int height;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using a single loop with stride simulation
    int index = 0;
    for (index = 0; index < width * height; ++index) {
        y = index / width;
        x = index % width;
    }
}
