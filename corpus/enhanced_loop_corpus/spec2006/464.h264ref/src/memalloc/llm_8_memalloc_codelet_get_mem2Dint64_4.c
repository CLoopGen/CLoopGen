#include <stdio.h>

#include <inttypes.h>

typedef int64_t int64;

extern int64 ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64 increment = columns * 2;
    for (i = 1; i < rows; i += 2) {
        if (i + 1 < rows) {
            (*array2D)[i]     = (*array2D)[i - 1] + increment;
            (*array2D)[i + 1] = (*array2D)[i]     + increment;
        } else {
            (*array2D)[i] = (*array2D)[i - 1] + columns;
        }
    }
}
