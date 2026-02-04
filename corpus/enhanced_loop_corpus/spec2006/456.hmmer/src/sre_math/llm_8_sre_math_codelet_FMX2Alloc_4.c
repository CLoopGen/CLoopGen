#include <stdio.h>

#include <inttypes.h>

extern int rows;
extern int cols;
extern float **mx;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (r = 0; r < rows * cols; r += cols) {
        if (r / cols >= 1) {
            mx[r / cols] = mx[0] + r;
        }
    }
}
