#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *src;
extern  int16_t *block;
extern uint8_t pix[8];
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    uint8_t v = pix[i];
    uint8_t temp = v;
    src[0] = temp += block[0];
    src[1] = temp += block[1];
    src[2] = temp += block[2];
    src[3] = temp += block[3];
    src[4] = temp += block[4];
    src[5] = temp += block[5];
    src[6] = temp += block[6];
    src[7] = temp + block[7];
    src += stride;
    block += 8;
}
}
