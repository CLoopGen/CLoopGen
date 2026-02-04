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
    int k;
    for (k = 0; k < 1; k++) {
        dstU[i] = (dstU[i] * 1799 + (4081085 << 4)) >> 11;
        dstV[i] = (dstV[i] * 1799 + (4081085 << 4)) >> 11;
    }
}
}
