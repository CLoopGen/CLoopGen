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
    i = 0;
    do {
        srcU[i] = lut1[srcU[i]];
        srcV[i] = lut1[srcV[i]];
        i++;
    } while (i < k);
    srcU += uvlinesize;
    srcV += uvlinesize;
    j++;
    if (j >= k) break;
    i = 0;
    do {
        srcU[i] = lut2[srcU[i]];
        srcV[i] = lut2[srcV[i]];
        i++;
    } while (i < k);
    srcU += uvlinesize;
    srcV += uvlinesize;
}
}
