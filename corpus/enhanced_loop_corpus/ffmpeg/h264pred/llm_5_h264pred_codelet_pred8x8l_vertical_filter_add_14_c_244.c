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
    src[0 * stride] = v += block[0];
    if (i % 2 == 0) {
        src[1 * stride] = v += block[8];
        src[2 * stride] = v += block[16];
        src[3 * stride] = v += block[24];
        src[4 * stride] = v += block[32];
        src[5 * stride] = v += block[40];
        src[6 * stride] = v += block[48];
        src[7 * stride] = v + block[56];
    } else {
        src[7 * stride] = v + block[56];
        src[6 * stride] = v + block[48];
        src[5 * stride] = v + block[40];
        src[4 * stride] = v + block[32];
        src[3 * stride] = v + block[24];
        src[2 * stride] = v + block[16];
        src[1 * stride] = v + block[8];
    }
    src++;
    block++;
}
}
