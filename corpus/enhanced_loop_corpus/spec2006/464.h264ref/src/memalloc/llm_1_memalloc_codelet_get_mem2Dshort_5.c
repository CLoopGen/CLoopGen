#include <stdio.h>

#include <inttypes.h>

extern short ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < rows; i++) {
        int j = 0;
        for (; j < 1; j++) {
            (*array2D)[i] = (*array2D)[i - 1] + columns;
        }
    }
}
