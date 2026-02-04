#include <stdio.h>

#include <inttypes.h>

extern int rows;
extern int cols;
extern float **mx;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 1; i++)
    for (r = 1; r < rows; r++)
        mx[r] = mx[0] + r * cols;
}
