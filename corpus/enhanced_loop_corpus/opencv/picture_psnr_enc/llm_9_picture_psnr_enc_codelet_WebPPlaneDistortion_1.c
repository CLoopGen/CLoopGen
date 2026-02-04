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
    int total_iterations = width * height * 5; // Increased trip count via unrolling effect
    int idx;
    for (idx = 0; idx < total_iterations; ++idx) {
        x = (idx % width);
        y = ((idx / width) % height);
        // Simulate heavier computation with repeated operations
        x = (x * x + 2 * x + 1) ^ 0xFF;
        y = (y * y + 2 * y + 1) ^ 0xFF;
    }
}
