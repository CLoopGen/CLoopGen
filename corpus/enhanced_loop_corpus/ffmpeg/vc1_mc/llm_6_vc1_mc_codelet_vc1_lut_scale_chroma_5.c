#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *srcU;
extern uint8_t *srcV;
extern uint8_t *lut1;
extern uint8_t *lut2;
extern int k;
extern int uvlinesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < k; j += 2) {
        uint8_t tempU, tempV;
        for (i = 0; i < k; i++) {
            tempU = srcU[i];
            tempV = srcV[i];
            srcU[i] = lut1[tempU];
            srcV[i] = lut1[tempV];
        }
        srcU += uvlinesize;
        srcV += uvlinesize;
        if (j + 1 == k)
            break;
        for (i = 0; i < k; i++) {
            tempU = srcU[i];
            tempV = srcV[i];
            srcU[i] = lut2[tempU];
            srcV[i] = lut2[tempV];
        }
        srcU += uvlinesize;
        srcV += uvlinesize;
    }
}
