#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dstU;
extern int16_t *dstV;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (width > 0) {
        dstU[0] = (dstU[0] * 1799 + 4081085) >> 11;
        dstV[0] = (dstV[0] * 1799 + 4081085) >> 11;
    }
    for (i = 1; i < width; i++) {
        dstU[i] = (dstU[i-1] * 1799 + 4081085) >> 11;
        dstV[i] = (dstV[i-1] * 1799 + 4081085) >> 11;
    }
}
