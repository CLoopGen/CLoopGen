#include <stdio.h>

#include <inttypes.h>

typedef unsigned char byte;

extern byte ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = step; i < rows; i += step) {
        (*array2D)[i] = (*array2D)[i - step] + columns * step;
        if (i + 1 < rows) {
            (*array2D)[i + 1] = (*array2D)[i] + columns;
        }
    }
}
