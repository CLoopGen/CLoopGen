#include <stdio.h>

#include <inttypes.h>

extern int rows;
extern int cols;
extern double **mx;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
for (i = 0; i < rows; i++)
    mx[i] = mx[0] + i * cols;
}
