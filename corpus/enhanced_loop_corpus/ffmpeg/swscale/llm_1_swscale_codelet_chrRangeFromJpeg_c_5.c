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
    for (i = 0; i < width; i += 2) {
        dstU[i] = (dstU[i] * 1799 + 4081085) >> 11;
        dstV[i] = (dstV[i] * 1799 + 4081085) >> 11;
        if (i + 1 < width) {
            dstU[i+1] = (dstU[i+1] * 1799 + 4081085) >> 11;
            dstV[i+1] = (dstV[i+1] * 1799 + 4081085) >> 11;
        }
    }
}
