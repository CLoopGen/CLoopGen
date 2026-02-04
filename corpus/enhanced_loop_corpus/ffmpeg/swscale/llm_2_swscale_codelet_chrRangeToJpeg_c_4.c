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
    int stride = 2;
    for (i = 0; i < width; i += stride) {
        if (i + 1 < width) {
            dstU[i] = (((dstU[i]) > (30775) ? (30775) : (dstU[i])) * 4663 - 9289992) >> 12;
            dstU[i+1] = (((dstU[i+1]) > (30775) ? (30775) : (dstU[i+1])) * 4663 - 9289992) >> 12;
            dstV[i] = (((dstV[i]) > (30775) ? (30775) : (dstV[i])) * 4663 - 9289992) >> 12;
            dstV[i+1] = (((dstV[i+1]) > (30775) ? (30775) : (dstV[i+1])) * 4663 - 9289992) >> 12;
        } else {
            dstU[i] = (((dstU[i]) > (30775) ? (30775) : (dstU[i])) * 4663 - 9289992) >> 12;
            dstV[i] = (((dstV[i]) > (30775) ? (30775) : (dstV[i])) * 4663 - 9289992) >> 12;
        }
    }
}
