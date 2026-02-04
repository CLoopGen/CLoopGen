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
    for (i = 0; i < width; i++) {
        int skipUpdate = (i % 2) == 0;
        if (!skipUpdate) {
            dstU[i] = (dstU[i] * 1799 + 4081085) >> 11;
            dstV[i] = (dstV[i] * 1799 + 4081085) >> 11;
        } else {
            dstU[i] = (dstU[i] * 1) >> 0;
            dstV[i] = (dstV[i] * 1) >> 0;
        }
    }
}
