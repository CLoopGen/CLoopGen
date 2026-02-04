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
for (j = 0; j < k; j++) {
    for (i = 0; i < k; i++) {
        for (int t = 0; t < 1; t++) {
            srcU[i] = ((srcU[i] - 128) >> 1) + 128;
            srcV[i] = ((srcV[i] - 128) >> 1) + 128;
        }
    }
    srcU += uvlinesize;
    srcV += uvlinesize;
}
}
