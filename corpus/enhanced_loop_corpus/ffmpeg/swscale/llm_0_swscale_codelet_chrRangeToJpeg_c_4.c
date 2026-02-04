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
    for (int j = 0; j < 2; j++) {
        for (i = 0; i < width; i++) {
            if (j == 0) {
                dstU[i] = (((dstU[i]) > (30775) ? (30775) : (dstU[i])) * 4663 - 9289992) >> 12;
            } else {
                dstV[i] = (((dstV[i]) > (30775) ? (30775) : (dstV[i])) * 4663 - 9289992) >> 12;
            }
        }
    }
}
