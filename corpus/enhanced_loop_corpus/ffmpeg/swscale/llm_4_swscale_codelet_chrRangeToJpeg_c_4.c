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
        int16_t valU = dstU[i];
        int16_t valV = dstV[i];

        if (valU <= 30775 && valV <= 30775) {
            dstU[i] = (valU * 4663 - 9289992) >> 12;
            dstV[i] = (valV * 4663 - 9289992) >> 12;
        } else {
            if (valU > 30775) valU = 30775;
            if (valV > 30775) valV = 30775;
            dstU[i] = (valU * 4663 - 9289992) >> 12;
            dstV[i] = (valV * 4663 - 9289992) >> 12;
        }
    }
}
