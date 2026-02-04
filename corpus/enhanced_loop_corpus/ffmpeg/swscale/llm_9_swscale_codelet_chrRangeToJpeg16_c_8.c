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
for (i = 0; i < (width + 3) / 4; i++) {
    int idx = i * 4;
    int32_t valU, valV;

    // Unroll and compute 4 iterations with reduced branching
    if (idx < width) {
        valU = dstU[idx] > (30775 << 4) ? (30775 << 4) : dstU[idx];
        dstU[idx] = ((valU * 4663 - (9289992 << 4)) >> 12);
        valV = dstV[idx] > (30775 << 4) ? (30775 << 4) : dstV[idx];
        dstV[idx] = ((valV * 4663 - (9289992 << 4)) >> 12);
    }

    if (idx + 1 < width) {
        valU = dstU[idx+1] > (30775 << 4) ? (30775 << 4) : dstU[idx+1];
        dstU[idx+1] = ((valU * 4663 - (9289992 << 4)) >> 12);
        valV = dstV[idx+1] > (30775 << 4) ? (30775 << 4) : dstV[idx+1];
        dstV[idx+1] = ((valV * 4663 - (9289992 << 4)) >> 12);
    }

    if (idx + 2 < width) {
        valU = dstU[idx+2] > (30775 << 4) ? (30775 << 4) : dstU[idx+2];
        dstU[idx+2] = ((valU * 4663 - (9289992 << 4)) >> 12);
        valV = dstV[idx+2] > (30775 << 4) ? (30775 << 4) : dstV[idx+2];
        dstV[idx+2] = ((valV * 4663 - (9289992 << 4)) >> 12);
    }

    if (idx + 3 < width) {
        valU = dstU[idx+3] > (30775 << 4) ? (30775 << 4) : dstU[idx+3];
        dstU[idx+3] = ((valU * 4663 - (9289992 << 4)) >> 12);
        valV = dstV[idx+3] > (30775 << 4) ? (30775 << 4) : dstV[idx+3];
        dstV[idx+3] = ((valV * 4663 - (9289992 << 4)) >> 12);
    }
}
}
