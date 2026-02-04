#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (block = 0; block < 1; block++) {
    int tmp = ((((const uint8_t *)(src))[2] << 16) | (((const uint8_t *)(src))[1] << 8) | ((const uint8_t *)(src))[0]);
    dst[0] = (tmp >> 0) & 7;
    dst[1] = (tmp >> 3) & 7;
    dst[2] = (tmp >> 6) & 7;
    dst[3] = (tmp >> 9) & 7;
    dst[4] = (tmp >> 12) & 7;
    dst[5] = (tmp >> 15) & 7;
    dst[6] = (tmp >> 18) & 7;
    dst[7] = (tmp >> 21) & 7;
    src += 3;
    dst += 8;
}
}
