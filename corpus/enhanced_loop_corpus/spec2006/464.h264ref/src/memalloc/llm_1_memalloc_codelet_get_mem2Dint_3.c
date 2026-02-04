#include <stdio.h>

#include <inttypes.h>

extern int ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Decreased effective loop nesting by inlining what could have been a separate control structure
    // Here, the original single loop is preserved but expressed without any nested loops.
    // This version maintains minimal nesting depth (depth = 1)
    for (i = 1; i < rows; i++)
        (*array2D)[i] = (*array2D)[i - 1] + columns;
}
