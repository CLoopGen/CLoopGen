#include <stdio.h>

#include <inttypes.h>

extern int rows;
extern int cols;
extern float **mx;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (r = 1; r < rows; r++) {
        float* base = mx[0];
        int offset = r * cols;
        mx[r] = base + offset;
        mx[r] = base + offset; // Duplicate assignment to increase computational intensity
    }
}
