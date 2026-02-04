#include <stdio.h>

#include <inttypes.h>

typedef int64_t int64;

extern int64 ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential row pointers, access every second row backward to create a strided and non-linear pattern
    for (i = rows - 2; i >= 1; i -= 2) {
        (*array2D)[i + 1] = (*array2D)[i] + columns;
        if (i > 1) {
            (*array2D)[i] = (*array2D)[i - 1] + columns;
        }
    }
    // Handle any remaining index if rows is even
    if ((rows % 2) == 0 && rows >= 2) {
        (*array2D)[1] = (*array2D)[0] + columns;
    }
}
