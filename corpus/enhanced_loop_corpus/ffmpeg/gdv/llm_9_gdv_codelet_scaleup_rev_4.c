#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x -= 4; x >= 0; x -= 4) {
        int idx = (x >> 1);
        uint8_t temp0 = src[idx + 0];
        uint8_t temp1 = src[idx + 1];

        dst[x + 0] = dst[x + 1] = temp0;
        dst[x + 2] = dst[x + 3] = temp1;
    }
}
