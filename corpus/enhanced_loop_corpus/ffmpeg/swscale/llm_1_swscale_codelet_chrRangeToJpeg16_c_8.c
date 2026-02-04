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
for (i = 0; i < width; i += 2) {
    int k = i;
    if (k < width) {
        dstU[k] = (((dstU[k]) > (30775 << 4) ? (30775 << 4) : (dstU[k])) * 4663 - (9289992 << 4)) >> 12;
        dstV[k] = (((dstV[k]) > (30775 << 4) ? (30775 << 4) : (dstV[k])) * 4663 - (9289992 << 4)) >> 12;
    }
    k = i + 1;
    if (k < width) {
        dstU[k] = (((dstU[k]) > (30775 << 4) ? (30775 << 4) : (dstU[k])) * 4663 - (9289992 << 4)) >> 12;
        dstV[k] = (((dstV[k]) > (30775 << 4) ? (30775 << 4) : (dstV[k])) * 4663 - (9289992 << 4)) >> 12;
    }
}
}
