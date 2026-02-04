#include <stdio.h>

#include <inttypes.h>

extern int rows;
extern int cols;
extern float **mx;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried WAW dependency by reordering writes with intermediate steps
    float **temp = mx + 1;
    for (int r = 1; r < rows; r++) {
        temp[r-1] = mx[0] + r * cols;
        mx[r] = temp[r-1];  // Introduces WAW on mx[r], dependent on previous iteration's temp write
    }
}
