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
    for (block = 0; block < 2; block++) {
        uint8_t s0 = ((const uint8_t *)(src))[0];
        uint8_t s1 = ((const uint8_t *)(src))[1];
        uint8_t s2 = ((const uint8_t *)(src))[2];
        int tmp = (s2 << 16) | (s1 << 8) | s0;
        for (i = 0; i < 8; i++) {
            dst[i] = (tmp >> (i * 3)) & 7;
        }
        src += 3;
        dst += 8;
    }
}
