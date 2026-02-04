#include <stdio.h>

#include <inttypes.h>

typedef unsigned char byte;

extern byte ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential row assignment, we process every other row (strided access by 2)
    // and then fill in the gaps. This changes spatial locality.
    int stride = 2;
    for (i = 1; i < rows; i += stride) {
        if (i + 1 < rows) {
            (*array2D)[i] = (*array2D)[i - 1] + columns;
            (*array2D)[i + 1] = (*array2D)[i] + columns;
        } else {
            (*array2D)[i] = (*array2D)[i - 1] + columns;
        }
    }
}
