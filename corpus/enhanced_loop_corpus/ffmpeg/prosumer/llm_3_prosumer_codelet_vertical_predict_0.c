#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *dst;
extern  uint32_t *src;
extern int stride;
extern int height;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < height; i++) {
    for (int j = 0; j < stride >> 2; j += 2) {
        int idx1 = j;
        int idx2 = (j + 1 < stride >> 2) ? j + 1 : j;
        dst[idx1] = (((src[idx1] >> 3) + (1061109567 & dst[idx1])) << 3) & 4244438268U;
        dst[idx2] = (((src[idx2] >> 3) + (1061109567 & dst[idx2])) << 3) & 4244438268U;
    }
    dst += stride >> 2;
    src += stride >> 2;
}
}
