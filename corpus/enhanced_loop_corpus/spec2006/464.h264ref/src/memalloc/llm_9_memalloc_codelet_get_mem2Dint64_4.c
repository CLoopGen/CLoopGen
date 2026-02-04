#include <stdio.h>

#include <inttypes.h>

typedef int64_t int64;

extern int64 ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64 step = columns + 1;
    for (i = 1; i < rows * 2; i++) {
        if (i % 2 == 1)
            (*array2D)[i / 2] = (*array2D)[(i - 1) / 2] + step;
    }
}
