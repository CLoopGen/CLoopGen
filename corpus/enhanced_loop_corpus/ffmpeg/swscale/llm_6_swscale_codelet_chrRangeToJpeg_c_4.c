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
    int16_t tempU, tempV;
    for (i = 0; i < width; i++) {
        tempU = dstU[i];
        tempV = dstV[i];
        if (tempU > 30775) tempU = 30775;
        if (tempV > 30775) tempV = 30775;
        dstU[i] = ((tempU * 4663 - 9289992) >> 12);
        dstV[i] = ((tempV * 4663 - 9289992) >> 12);
    }
}
