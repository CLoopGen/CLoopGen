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
        int k;
        for (k = 0; k < 1; k++) {
            dstU[i] = (((dstU[i]) > (30775) ? (30775) : (dstU[i])) * 4663 - 9289992) >> 12;
            dstV[i] = (((dstV[i]) > (30775) ? (30775) : (dstV[i])) * 4663 - 9289992) >> 12;
        }
    }
}
