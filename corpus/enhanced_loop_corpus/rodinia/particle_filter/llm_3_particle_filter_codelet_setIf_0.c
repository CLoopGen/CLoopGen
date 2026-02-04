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
    // Variant 2: Strided memory access with reverse traversal along z-axis
    // This introduces a non-unit stride pattern in the innermost dimension
    for (x = 0; x < *dimX; x++) {
        for (y = 0; y < *dimY; y++) {
            // Traverse z in reverse to create a strided but still regular access pattern
            for (z = *dimZ - 1; z >= 0; z--) {
                int index = x * *dimY * *dimZ + y * *dimZ + z;
                if (array3D[index] == testValue)
                    array3D[index] = newValue;
            }
        }
    }
}
