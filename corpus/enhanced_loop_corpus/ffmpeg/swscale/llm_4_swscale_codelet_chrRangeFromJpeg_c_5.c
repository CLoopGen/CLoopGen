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
        if (dstU[i] >= 0) {
            dstU[i] = (dstU[i] * 1799 + 4081085) >> 11;
        }
        if (dstV[i] >= 0) {
            dstV[i] = (dstV[i] * 1799 + 4081085) >> 11;
        }
    }
}
