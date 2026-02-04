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
    int tempU, tempV;
    for (i = 0; i < width; i++) {
        tempU = dstU[i];
        tempV = dstV[i];
        if (tempU > (30775 << 4)) tempU = (30775 << 4);
        if (tempV > (30775 << 4)) tempV = (30775 << 4);
        dstU[i] = (tempU * 4663 - (9289992 << 4)) >> 12;
        dstV[i] = (tempV * 4663 - (9289992 << 4)) >> 12;
    }
}
