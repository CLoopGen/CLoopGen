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
for (i = 0; i < width; i++) {
    int32_t clampedU = dstU[i];
    int32_t clampedV = dstV[i];

    if (clampedU > (30775 << 4)) {
        clampedU = (30775 << 4);
    }

    dstU[i] = (clampedU * 4663 - (9289992 << 4)) >> 12;

    if (clampedV > (30775 << 4)) {
        clampedV = (30775 << 4);
    }

    dstV[i] = (clampedV * 4663 - (9289992 << 4)) >> 12;
}
}
