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
uint8_t local_pix[8];
int16_t local_block[64];
for (i = 0; i < 8; i++) {
    local_pix[i] = pix[i];
}
for (i = 0; i < 64; i++) {
    local_block[i] = block[i];
}
for (i = 0; i < 8; i++) {
    uint8_t v = local_pix[i];
    v += local_block[0 + i];
    src[0 * stride] = v;
    v += local_block[8 + i];
    src[1 * stride] = v;
    v += local_block[16 + i];
    src[2 * stride] = v;
    v += local_block[24 + i];
    src[3 * stride] = v;
    v += local_block[32 + i];
    src[4 * stride] = v;
    v += local_block[40 + i];
    src[5 * stride] = v;
    v += local_block[48 + i];
    src[6 * stride] = v;
    v += local_block[56 + i];
    src[7 * stride] = v;
    src++;
}
block += 8;
}
