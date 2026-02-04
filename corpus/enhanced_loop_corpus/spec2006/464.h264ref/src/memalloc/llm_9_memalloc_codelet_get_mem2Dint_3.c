#include <stdio.h>

#include <inttypes.h>

extern int ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 2; i < rows; i += step) {
        (*array2D)[i] = (*array2D)[i - 2] + (columns << 1);
    }
}
