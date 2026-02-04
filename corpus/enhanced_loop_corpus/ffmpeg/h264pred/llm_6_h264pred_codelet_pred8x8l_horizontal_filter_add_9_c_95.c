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
    for (i = 0; i < 8; i++) {
        uint16_t v = pix[i];
        uint16_t temp = v;
        temp += block[0]; src[0] = temp;
        temp += block[1]; src[1] = temp;
        temp += block[2]; src[2] = temp;
        temp += block[3]; src[3] = temp;
        temp += block[4]; src[4] = temp;
        temp += block[5]; src[5] = temp;
        temp += block[6]; src[6] = temp;
        temp += block[7]; src[7] = temp;
        src += stride;
        block += 8;
    }
}
