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
    int k;
    for (k = 0; k < width; k += 2) {
        if (k + 1 < width) {
            dstU[k] = (dstU[k] * 1799 + (4081085 << 4)) >> 11;
            dstV[k] = (dstV[k] * 1799 + (4081085 << 4)) >> 11;
            dstU[k+1] = (dstU[k+1] * 1799 + (4081085 << 4)) >> 11;
            dstV[k+1] = (dstV[k+1] * 1799 + (4081085 << 4)) >> 11;
        } else {
            dstU[k] = (dstU[k] * 1799 + (4081085 << 4)) >> 11;
            dstV[k] = (dstV[k] * 1799 + (4081085 << 4)) >> 11;
        }
    }
}
