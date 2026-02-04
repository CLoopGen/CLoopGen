#include <stdio.h>

#include <inttypes.h>

typedef int64_t int64;

extern int64 ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64 **temp = *array2D;
    for (i = 1; i < rows; i++) {
        temp[i] = temp[i - 1] + columns;
    }
}
