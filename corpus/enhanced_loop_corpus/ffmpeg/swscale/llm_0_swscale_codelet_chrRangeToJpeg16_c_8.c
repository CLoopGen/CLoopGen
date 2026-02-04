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
for (j = 0; j < 1; j++) {
    for (i = 0; i < width; i++) {
        dstU[i] = (((dstU[i]) > (30775 << 4) ? (30775 << 4) : (dstU[i])) * 4663 - (9289992 << 4)) >> 12;
        dstV[i] = (((dstV[i]) > (30775 << 4) ? (30775 << 4) : (dstV[i])) * 4663 - (9289992 << 4)) >> 12;
    }
}
}
