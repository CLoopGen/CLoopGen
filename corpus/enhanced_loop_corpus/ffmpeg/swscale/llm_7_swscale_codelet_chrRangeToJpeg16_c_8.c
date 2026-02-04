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
    int offset = 0;
    while (offset < width) {
        int idx = offset;
        int32_t valU = dstU[idx];
        int32_t valV = dstV[idx];
        valU = (valU > (30775 << 4)) ? (30775 << 4) : valU;
        valV = (valV > (30775 << 4)) ? (30775 << 4) : valV;
        dstU[idx] = (valU * 4663 - (9289992 << 4)) >> 12;
        dstV[idx] = (valV * 4663 - (9289992 << 4)) >> 12;
        offset++;
    }
}
