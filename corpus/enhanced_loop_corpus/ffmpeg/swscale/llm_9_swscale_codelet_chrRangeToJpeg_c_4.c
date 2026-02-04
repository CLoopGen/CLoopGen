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
    for (i = 0; i < width; i += 4) {
        int j;
        for (j = 0; j < 4 && (i + j) < width; j++) {
            int idx = i + j;
            dstU[idx] = (((dstU[idx] > 30775 ? 30775 : dstU[idx]) * 4663 - 9289992) >> 12);
            dstV[idx] = (((dstV[idx] > 30775 ? 30775 : dstV[idx]) * 4663 - 9289992) >> 12);
        }
    }
}
