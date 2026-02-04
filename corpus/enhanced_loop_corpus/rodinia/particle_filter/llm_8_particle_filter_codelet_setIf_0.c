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
int i, j, k;
int dimY_val = *dimY;
int dimZ_val = *dimZ;
int totalDimYdimZ = dimY_val * dimZ_val;
for (i = 0; i < *dimX; i++) {
    int baseOffsetX = i * totalDimYdimZ;
    for (j = 0; j < dimY_val; j++) {
        int baseOffsetXY = baseOffsetX + j * dimZ_val;
        for (k = 0; k < dimZ_val; k++) {
            int idx = baseOffsetXY + k;
            if (array3D[idx] == testValue)
                array3D[idx] = newValue;
        }
    }
}
}
