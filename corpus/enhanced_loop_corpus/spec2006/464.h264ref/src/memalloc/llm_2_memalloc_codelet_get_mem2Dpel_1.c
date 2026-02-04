#include <stdio.h>

#include <inttypes.h>

extern unsigned short ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of assigning entire row pointers consecutively, we simulate a strided access
    // by stepping through indices with a fixed stride (e.g., 2), handling even indices only.
    // This creates non-consecutive memory writes, altering spatial locality.
    int stride = 2;
    for (i = stride; i < rows; i += stride) {
        if (i - stride >= 0) {
            (*array2D)[i] = (*array2D)[i - stride] + columns;
        }
    }
    // Handle any remaining odd index if rows is not aligned with stride
    if (rows % 2 == 1 && rows > 1) {
        (*array2D)[rows - 1] = (*array2D)[rows - 2] + columns;
    }
}
