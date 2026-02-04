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
    int tmp1 = (((const uint8_t *)(src))[0]);
    int tmp2 = (((const uint8_t *)(src))[1] << 8);
    int tmp3 = (((const uint8_t *)(src))[2] << 16);
    int tmp = tmp1 | tmp2 | tmp3;
    for (i = 0; i < 8; i++) {
        dst[i] = (tmp >> (i * 3)) & 7;
    }
    src += 3;
    dst += 8;
}
}
