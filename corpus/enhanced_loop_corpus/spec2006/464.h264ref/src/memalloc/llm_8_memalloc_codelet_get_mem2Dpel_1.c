#include <stdio.h>

#include <inttypes.h>

extern unsigned short ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 1; i < rows; i++) {
        (*array2D)[i] = (*array2D)[i - 1] + columns;
        for (j = 0; j < columns; j++) {
            (*array2D)[i][j] += j;
        }
    }
}
