#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int testValue;
extern int newValue;
extern int *array3D;
extern int *dimX;
extern int *dimY;
extern int *dimZ;
extern int x;
extern int y;
extern int z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the iteration order
    // We traverse the 3D array as a 1D contiguous block, which improves cache locality
    int totalElements = *dimX * *dimY * *dimZ;
    for (int i = 0; i < totalElements; i++) {
        if (array3D[i] == testValue)
            array3D[i] = newValue;
    }
}
