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
for (i = 0; i < 4; i++) {
    uint16_t v0 = pix[i];
    uint16_t v1 = pix[i + 4];
    src[0 * stride] = v0 += block[0];
    src[1 * stride] = v0 += block[8];
    src[2 * stride] = v0 += block[16];
    src[3 * stride] = v0 += block[24];
    src[4 * stride] = v1 += block[32];
    src[5 * stride] = v1 += block[40];
    src[6 * stride] = v1 += block[48];
    src[7 * stride] = v1 + block[56];
    src++;
    block++;
}
}
