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
        if (i + 1 < width) {
            dstU[i] = (dstU[i] * 1799 + (4081085 << 4)) >> 11;
            dstU[i+1] = (dstU[i+1] * 1799 + (4081085 << 4)) >> 11;
            dstV[i] = (dstV[i] * 1799 + (4081085 << 4)) >> 11;
            dstV[i+1] = (dstV[i+1] * 1799 + (4081085 << 4)) >> 11;
        } else {
            dstU[i] = (dstU[i] * 1799 + (4081085 << 4)) >> 11;
            dstV[i] = (dstV[i] * 1799 + (4081085 << 4)) >> 11;
        }
    }
}
