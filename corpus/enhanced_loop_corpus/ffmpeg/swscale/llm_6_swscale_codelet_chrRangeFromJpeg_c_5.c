#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dstU;
extern int16_t *dstV;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    int16_t tempU, tempV;
    for (i = 0; i < width; i++) {
        tempU = dstU[i];
        tempV = dstV[i];
        dstU[i] = (tempU * 1799 + 4081085) >> 11;
        dstV[i] = (tempV * 1799 + 4081085) >> 11;
    }
}
