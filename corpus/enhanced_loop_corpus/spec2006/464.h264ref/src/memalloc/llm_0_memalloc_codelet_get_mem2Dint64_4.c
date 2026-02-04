#include <stdio.h>

#include <inttypes.h>

typedef int64_t int64;

extern int64 ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < 1; j++)
    for (i = 1; i < rows; i++)
        (*array2D)[i] = (*array2D)[i - 1] + columns;
}
