#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *srcU;
extern uint8_t *srcV;
extern int k;
extern int uvlinesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j, i;
    uint8_t tempU, tempV;
    for (j = 0; j < k; j++) {
        for (i = 0; i < k; i++) {
            tempU = srcU[i] - 128;
            tempV = srcV[i] - 128;
            srcU[i] = (tempU >> 1) + 128;
            srcV[i] = (tempV >> 1) + 128;
        }
        srcU += uvlinesize;
        srcV += uvlinesize;
    }
}
