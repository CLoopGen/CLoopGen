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
    int idx, baseXY;
    for (x = 0; x < *dimX; x++) {
        baseXY = x * *dimY * *dimZ;
        for (y = 0; y < *dimY; y++) {
            idx = baseXY + y * *dimZ;
            for (z = 0; z < *dimZ; z++) {
                int currentIdx = idx + z;
                if (array3D[currentIdx] == testValue) {
                    array3D[currentIdx] = newValue;
                }
            }
        }
    }
}
