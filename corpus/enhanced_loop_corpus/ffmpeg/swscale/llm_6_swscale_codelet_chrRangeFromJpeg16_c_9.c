#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *dstU;
extern int32_t *dstV;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < width; j++) {
        int32_t tempU = dstU[j] * 1799 + (4081085 << 4);
        int32_t tempV = dstV[j] * 1799 + (4081085 << 4);
        dstU[j] = tempU >> 11;
        dstV[j] = tempV >> 11;
    }
}
