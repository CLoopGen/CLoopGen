#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int w;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w - 7; x += 8) {
        int src_idx = (x >> 1);
        uint8_t temp0 = src[src_idx + 0];
        uint8_t temp1 = src[src_idx + 1];
        uint8_t temp2 = src[src_idx + 2];
        uint8_t temp3 = src[src_idx + 3];
        dst[x + 0] = temp0;
        dst[x + 1] = temp0;
        dst[x + 2] = temp1;
        dst[x + 3] = temp1;
        dst[x + 4] = temp2;
        dst[x + 5] = temp2;
        dst[x + 6] = temp3;
        dst[x + 7] = temp3;
    }
}
