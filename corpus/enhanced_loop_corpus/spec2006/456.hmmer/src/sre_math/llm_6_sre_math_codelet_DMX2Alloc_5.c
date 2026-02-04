#include <stdio.h>

#include <inttypes.h>

extern int rows;
extern int cols;
extern double **mx;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce a loop-carried WAW dependency by making each iteration depend on the previous one
    // This creates a write-after-write dependency on mx[r-1], which must be preserved
    if (rows > 1) {
        mx[1] = mx[0] + cols;
        for (r = 2; r < rows; r++) {
            mx[r] = mx[r-1] + cols;  // Each assignment depends on prior write
        }
    }
}
