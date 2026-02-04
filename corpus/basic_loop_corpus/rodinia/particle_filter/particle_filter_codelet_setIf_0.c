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
for (x = 0; x < *dimX; x++) {
    for (y = 0; y < *dimY; y++) {
        for (z = 0; z < *dimZ; z++) {
            if (array3D[x * *dimY * *dimZ + y * *dimZ + z] == testValue)
                array3D[x * *dimY * *dimZ + y * *dimZ + z] = newValue;
        }
    }
}

}
