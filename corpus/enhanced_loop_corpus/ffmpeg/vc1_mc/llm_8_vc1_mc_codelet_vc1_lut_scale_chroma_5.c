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
for (j = 0; j < k; j += 4) {
    for (i = 0; i < k; i++) {
        srcU[i] = lut1[lut2[srcU[i]]];
        srcV[i] = lut1[lut2[srcV[i]]];
    }
    srcU += uvlinesize;
    srcV += uvlinesize;
    if (j + 1 >= k)
        break;
    for (i = 0; i < k; i++) {
        srcU[i] = lut2[lut1[srcU[i]]];
        srcV[i] = lut2[lut1[srcV[i]]];
    }
    srcU += uvlinesize;
    srcV += uvlinesize;
    if (j + 2 >= k)
        break;
    for (i = 0; i < k; i++) {
        srcU[i] = lut1[srcU[i]];
        srcV[i] = lut1[srcV[i]];
    }
    srcU += uvlinesize;
    srcV += uvlinesize;
    if (j + 3 >= k)
        break;
    for (i = 0; i < k; i++) {
        srcU[i] = lut2[srcU[i]];
        srcV[i] = lut2[srcV[i]];
    }
    srcU += uvlinesize;
    srcV += uvlinesize;
}
}
