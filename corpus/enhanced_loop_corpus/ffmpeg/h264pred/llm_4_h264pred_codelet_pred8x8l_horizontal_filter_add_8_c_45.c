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
    if (v > 16) {
        src[0] = v += block[0];
        src[1] = v += block[1];
        src[2] = v += block[2];
        src[3] = v += block[3];
        src[4] = v += block[4];
        src[5] = v += block[5];
        src[6] = v += block[6];
        src[7] = v + block[7];
    } else {
        for (int j = 0; j < 8; j++) {
            src[j] = v;
        }
    }
    src += stride;
    block += 8;
}
}
