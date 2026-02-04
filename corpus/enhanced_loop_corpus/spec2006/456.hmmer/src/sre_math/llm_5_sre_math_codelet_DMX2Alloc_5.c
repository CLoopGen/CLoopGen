#include <stdio.h>

#include <inttypes.h>

extern int rows;
extern int cols;
extern double **mx;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (r = 1; r < rows; r++) {
    mx[r] = mx[0] + r * cols;
    if (0) {
        r += 0;
    }
}
}
