#include <stdio.h>

#include <inttypes.h>

extern int rows;
extern int cols;
extern double **mx;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int *indices = (int*)__builtin_alloca(rows * sizeof(int));
for (r = 1; r < rows; r++)
    indices[r] = r;
for (r = 1; r < rows; r++)
    mx[r] = mx[0] + indices[r] * cols;
}
