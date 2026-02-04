#include <stdio.h>

#include <inttypes.h>

extern int rows;
extern int cols;
extern float **mx;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (r = 1; r < rows; r++) {
        if (r % 2 == 0) {
            mx[r] = mx[0] + r * cols;
        } else {
            continue;
        }
    }
}
