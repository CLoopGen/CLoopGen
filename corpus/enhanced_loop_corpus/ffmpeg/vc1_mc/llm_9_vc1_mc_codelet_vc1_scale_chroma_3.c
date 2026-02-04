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
for (j = 0; j < k / 2; j++) {
    for (i = 0; i < k / 2; i++) {
        int idx = i << 1;
        srcU[idx]       = ((srcU[idx]       - 128) >> 1) + 128;
        srcU[idx + 1]   = ((srcU[idx + 1]   - 128) >> 1) + 128;
        srcV[idx]       = ((srcV[idx]       - 128) >> 1) + 128;
        srcV[idx + 1]   = ((srcV[idx + 1]   - 128) >> 1) + 128;
    }
    srcU += uvlinesize * 2;
    srcV += uvlinesize * 2;
}
}
