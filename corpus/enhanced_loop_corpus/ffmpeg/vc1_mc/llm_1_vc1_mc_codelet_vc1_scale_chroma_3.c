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
for (int idx = 0; idx < k * k; idx++) {
    i = idx % k;
    j = idx / k;
    srcU[i] = ((srcU[i] - 128) >> 1) + 128;
    srcV[i] = ((srcV[i] - 128) >> 1) + 128;
    if (i == k - 1) {
        srcU += uvlinesize;
        srcV += uvlinesize;
    }
}
}
