#include <stdio.h>

#include <inttypes.h>

typedef unsigned char byte;

extern byte ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 1; j < rows; j++) {
        (*array2D)[j] = (*array2D)[0] + j * columns;
    }
}
