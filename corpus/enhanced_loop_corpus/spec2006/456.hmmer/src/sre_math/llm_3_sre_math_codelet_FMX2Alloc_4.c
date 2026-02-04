#include <stdio.h>

#include <inttypes.h>

extern int rows;
extern int cols;
extern float **mx;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access pattern - simulate stride by stepping through a flattened index
    // Here we maintain the same assignment but introduce a strided traversal conceptually via index scaling
    for (r = 1; r < rows; r++) {
        int offset = r * cols;  // Stride of 'cols' elements per row
        mx[r] = &mx[0][offset];
    }
}
