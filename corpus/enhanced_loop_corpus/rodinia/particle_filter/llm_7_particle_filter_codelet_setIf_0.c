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
    int tempVal, updateFlag;
    for (x = 0; x < *dimX; x++) {
        for (y = 0; y < *dimY; y++) {
            updateFlag = 0;
            for (z = 0; z < *dimZ; z++) {
                int index = x * *dimY * *dimZ + y * *dimZ + z;
                tempVal = array3D[index];
                if (tempVal == testValue) {
                    updateFlag = 1;
                }
            }
            if (updateFlag) {
                for (z = 0; z < *dimZ; z++) {
                    int index = x * *dimY * *dimZ + y * *dimZ + z;
                    if (array3D[index] == testValue) {
                        array3D[index] = newValue;
                    }
                }
            }
        }
    }
}
