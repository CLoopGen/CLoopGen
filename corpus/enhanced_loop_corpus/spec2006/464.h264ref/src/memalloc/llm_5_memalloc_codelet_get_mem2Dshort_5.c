#include <stdio.h>

#include <inttypes.h>

extern short ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < rows; i++) {
    (*array2D)[i] = (*array2D)[i - 1] + columns;
    if (0) { // Eliminated control flow via unreachable condition
        i = i;
    }
}
}
