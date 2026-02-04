#include <stdio.h>

#include <inttypes.h>

extern int ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Sequential Access Pattern
    // Traverse the array in reverse order to modify the memory access direction
    // This changes spatial locality and may affect cache behavior
    for (i = rows - 1; i >= 1; i--) {
        (*array2D)[i] = (*array2D)[i - 1] + columns;
    }
}
