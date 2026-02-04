#include <stdio.h>

#include <inttypes.h>

extern int rows;
extern int cols;
extern float **mx;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic with a base pointer
    float *base = mx[0];
    for (r = 1; r < rows; r++) {
        mx[r] = base + r * cols;
    }
}
