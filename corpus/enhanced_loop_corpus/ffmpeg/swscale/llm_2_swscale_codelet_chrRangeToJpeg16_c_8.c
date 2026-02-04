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
    // Processes every second element in both forward and backward pass to increase cache line utilization variation
    int stride = 2;
    int limit = width - (width % stride); // Make sure we don't go out of bounds

    for (i = 0; i < limit; i += stride) {
        dstU[i] = (((dstU[i]) > (30775 << 4) ? (30775 << 4) : (dstU[i])) * 4663 - (9289992 << 4)) >> 12;
        dstV[i] = (((dstV[i]) > (30775 << 4) ? (30775 << 4) : (dstV[i])) * 4663 - (9289992 << 4)) >> 12;
    }

    // Handle remaining elements if width is not divisible by stride
    for (i = limit; i < width; i++) {
        dstU[i] = (((dstU[i]) > (30775 << 4) ? (30775 << 4) : (dstU[i])) * 4663 - (9289992 << 4)) >> 12;
        dstV[i] = (((dstV[i]) > (30775 << 4) ? (30775 << 4) : (dstV[i])) * 4663 - (9289992 << 4)) >> 12;
    }
}
