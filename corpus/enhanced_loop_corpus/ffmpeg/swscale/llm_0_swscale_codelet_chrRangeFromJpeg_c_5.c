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
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < width; i++) {
            dstU[i] = (dstU[i] * 1799 + 4081085) >> 11;
            dstV[i] = (dstV[i] * 1799 + 4081085) >> 11;
        }
    }
}
