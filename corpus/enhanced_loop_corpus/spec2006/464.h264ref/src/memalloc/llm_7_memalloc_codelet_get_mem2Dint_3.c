#include <stdio.h>

#include <inttypes.h>

extern int ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int **temp = *array2D;
    for (i = 0; i < rows - 1; i++) {
        temp[i + 1] = temp[i] + columns;
    }
}
