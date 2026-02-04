#include <stdio.h>

#include <inttypes.h>

extern unsigned short ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    unsigned short **temp = *array2D;
    for (i = 1; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            temp[i][j] = temp[i-1][j] + 1;
        }
    }
}
