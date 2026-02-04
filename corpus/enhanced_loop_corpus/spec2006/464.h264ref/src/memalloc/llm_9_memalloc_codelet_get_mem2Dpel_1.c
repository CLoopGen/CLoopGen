#include <stdio.h>

#include <inttypes.h>

extern unsigned short ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = step; i < rows; i += step) {
        (*array2D)[i] = (*array2D)[i - step] + columns * step;
    }
    if (rows > 0 && (rows - 1) % step != 0) {
        (*array2D)[rows - 1] = (*array2D)[rows - 2] + columns;
    }
}
