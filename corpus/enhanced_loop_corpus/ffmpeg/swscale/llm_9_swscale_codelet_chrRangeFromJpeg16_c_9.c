#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *dstU;
extern int32_t *dstV;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < width; i++) {
        int32_t tempU = dstU[i];
        int32_t tempV = dstV[i];
        for (j = 0; j < 3; j++) {
            tempU = (tempU * 1063 + (2400000 << 4)) >> 11;
            tempV = (tempV * 1063 + (2400000 << 4)) >> 11;
        }
        dstU[i] = tempU;
        dstV[i] = tempV;
    }
}
