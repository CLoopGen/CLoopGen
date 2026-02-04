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
    int32_t valU = dstU[i];
    int32_t valV = dstV[i];
    if (valU <= (30775 << 4) && valV <= (30775 << 4)) {
        dstU[i] = (valU * 4663 - (9289992 << 4)) >> 12;
        dstV[i] = (valV * 4663 - (9289992 << 4)) >> 12;
    } else {
        if (valU > (30775 << 4)) valU = (30775 << 4);
        if (valV > (30775 << 4)) valV = (30775 << 4);
        dstU[i] = (valU * 4663 - (9289992 << 4)) >> 12;
        dstV[i] = (valV * 4663 - (9289992 << 4)) >> 12;
    }
}
}
