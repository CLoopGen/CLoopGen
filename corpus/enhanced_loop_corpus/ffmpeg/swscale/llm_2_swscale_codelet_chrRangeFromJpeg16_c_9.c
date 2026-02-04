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
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < width; i += 2) {
        if (i + 0 < width) {
            dstU[i] = (dstU[i] * 1799 + (4081085 << 4)) >> 11;
            dstV[i] = (dstV[i] * 1799 + (4081085 << 4)) >> 11;
        }
        if (i + 1 < width) {
            dstU[i + 1] = (dstU[i + 1] * 1799 + (4081085 << 4)) >> 11;
            dstV[i + 1] = (dstV[i + 1] * 1799 + (4081085 << 4)) >> 11;
        }
    }
}
