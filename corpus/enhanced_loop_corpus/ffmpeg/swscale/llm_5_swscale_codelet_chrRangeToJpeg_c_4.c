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
        int16_t clampedU = dstU[i];
        int16_t clampedV = dstV[i];

        if (clampedU > 30775) {
            clampedU = 30775;
        }
        dstU[i] = (clampedU * 4663 - 9289992) >> 12;

        if (clampedV > 30775) {
            clampedV = 30775;
        }
        dstV[i] = (clampedV * 4663 - 9289992) >> 12;
    }
}
