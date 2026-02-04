#include <stdio.h>

#include <inttypes.h>

extern int rows;
extern int cols;
extern float **mx;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (rows > 1)
    for (r = 1; r < rows; r++)
        for (int c = 0; c < 1; c++)
            mx[r] = mx[0] + r * cols;
}
