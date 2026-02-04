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
    // Variant 1: Strided memory access with stride of 2
    for (j = 0; j < k; j++) {
        for (i = 0; i < k; i += 2) {
            if (i + 1 < k) {
                srcU[i]     = ((srcU[i]     - 128) >> 1) + 128;
                srcU[i + 1] = ((srcU[i + 1] - 128) >> 1) + 128;
                srcV[i]     = ((srcV[i]     - 128) >> 1) + 128;
                srcV[i + 1] = ((srcV[i + 1] - 128) >> 1) + 128;
            } else {
                srcU[i] = ((srcU[i] - 128) >> 1) + 128;
                srcV[i] = ((srcV[i] - 128) >> 1) + 128;
            }
        }
        srcU += uvlinesize;
        srcV += uvlinesize;
    }
}
