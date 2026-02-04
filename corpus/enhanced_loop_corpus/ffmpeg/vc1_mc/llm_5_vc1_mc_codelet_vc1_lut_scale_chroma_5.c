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
    int limit = (k % 2 == 0) ? k : k - 1;
    for (j = 0; j < limit; j += 2) {
        for (i = 0; i < k; i++) {
            uint8_t u_val = srcU[i];
            uint8_t v_val = srcV[i];
            srcU[i] = lut1[u_val];
            srcV[i] = lut1[v_val];
        }
        srcU += uvlinesize;
        srcV += uvlinesize;

        for (i = 0; i < k; i++) {
            uint8_t u_val = srcU[i];
            uint8_t v_val = srcV[i];
            srcU[i] = lut2[u_val];
            srcV[i] = lut2[v_val];
        }
        srcU += uvlinesize;
        srcV += uvlinesize;
    }

    if (limit < k) {
        for (i = 0; i < k; i++) {
            srcU[i] = lut1[srcU[i]];
            srcV[i] = lut1[srcV[i]];
        }
    }
}
