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
for (j = 0; j < k; j++) {
    for (i = 0; i < k; i += 2) {
        uint8_t tempU1 = srcU[i], tempV1 = srcV[i];
        uint8_t tempU2 = (i + 1 < k) ? srcU[i + 1] : tempU1;
        uint8_t tempV2 = (i + 1 < k) ? srcV[i + 1] : tempV1;

        srcU[i] = lut1[tempU1];
        srcV[i] = lut1[tempV1];
        if (i + 1 < k) {
            srcU[i + 1] = lut1[tempU2];
            srcV[i + 1] = lut1[tempV2];
        }
    }
    srcU += uvlinesize;
    srcV += uvlinesize;

    if (j % 2 == 1) continue;

    for (i = 0; i < k; i += 2) {
        uint8_t tempU1 = srcU[i], tempV1 = srcV[i];
        uint8_t tempU2 = (i + 1 < k) ? srcU[i + 1] : tempU1;
        uint8_t tempV2 = (i + 1 < k) ? srcV[i + 1] : tempV1;

        srcU[i] = lut2[tempU1];
        srcV[i] = lut2[tempV1];
        if (i + 1 < k) {
            srcU[i + 1] = lut2[tempU2];
            srcV[i + 1] = lut2[tempV2];
        }
    }
    srcU += uvlinesize;
    srcV += uvlinesize;
}
}
