#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *src;
extern  int32_t *block;
extern uint16_t pix[8];
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint16_t acc = 0;
for (i = 0; i < 8; i++) {
    uint16_t v = pix[i];
    acc += v;
    src[0] = acc += block[0];
    src[1] = acc += block[1];
    src[2] = acc += block[2];
    src[3] = acc += block[3];
    src[4] = acc += block[4];
    src[5] = acc += block[5];
    src[6] = acc += block[6];
    src[7] = acc + block[7];
    src += stride;
    block += 8;
}
}
