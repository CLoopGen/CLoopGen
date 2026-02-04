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
for (block = 0; block < 4; block++) {
    int tmp1 = ((((const uint8_t *)(src))[0] << 0) | (((const uint8_t *)(src))[1] << 8));
    int tmp2 = ((((const uint8_t *)(src))[2] << 0));
    for (i = 0; i < 8; i++) {
        if (i < 6) {
            dst[i] = (tmp1 >> (i * 3)) & 7;
        } else {
            dst[i] = (tmp2 >> ((i - 6) * 3)) & 7;
        }
    }
    src += 3;
    dst += 8;
}
}
