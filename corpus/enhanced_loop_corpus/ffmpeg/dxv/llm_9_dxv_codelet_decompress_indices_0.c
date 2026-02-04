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
    for (i = 0; i < 4; i++) {
        dst[i * 2] = (tmp >> (i * 6)) & 7;
        dst[i * 2 + 1] = (tmp >> (i * 6 + 3)) & 7;
    }
    src += 3;
    dst += 8;
}
}
