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
for (i = 0; i < 4; i++) {
    uint8_t v = pix[i];
    src[0 * stride] = v += block[0];
    src[1 * stride] = v += block[8];
    src[2 * stride] = v += block[16];
    src[3 * stride] = v += block[24];
    src++;
    block++;
}
}
