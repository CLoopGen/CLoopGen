#include <stdio.h>

#include <inttypes.h>

extern int ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential row assignment, we access elements with a stride of 2 (every other row)
    // This creates a strided memory access pattern, skipping one row at a time.
    for (i = 2; i < rows; i += 2) {
        (*array2D)[i] = (*array2D)[i - 2] + 2 * columns;
    }
}
