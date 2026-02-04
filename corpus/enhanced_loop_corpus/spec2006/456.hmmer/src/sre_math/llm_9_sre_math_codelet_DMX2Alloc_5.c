#include <stdio.h>

#include <inttypes.h>

extern int rows;
extern int cols;
extern double **mx;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i, j;
for (i = 1; i < rows; i++) {
    mx[i] = mx[0] + i * cols;
    for (j = 0; j < cols; j++) {
        mx[i][j] *= 2.0;
    }
}
}
