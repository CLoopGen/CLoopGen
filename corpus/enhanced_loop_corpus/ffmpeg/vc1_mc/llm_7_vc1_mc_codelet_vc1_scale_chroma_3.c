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
    uint8_t *local_srcU = srcU;
    uint8_t *local_srcV = srcV;
    for (j = 0; j < k; j++) {
        for (i = 0; i < k; i += 2) {
            if (i + 1 < k) {
                local_srcU[i]     = ((local_srcU[i]     - 128) >> 1) + 128;
                local_srcV[i]     = ((local_srcV[i]     - 128) >> 1) + 128;
                local_srcU[i + 1] = ((local_srcU[i + 1] - 128) >> 1) + 128;
                local_srcV[i + 1] = ((local_srcV[i + 1] - 128) >> 1) + 128;
            } else {
                local_srcU[i] = ((local_srcU[i] - 128) >> 1) + 128;
                local_srcV[i] = ((local_srcV[i] - 128) >> 1) + 128;
            }
        }
        local_srcU += uvlinesize;
        local_srcV += uvlinesize;
    }
    srcU = local_srcU;
    srcV = local_srcV;
}
