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
    int offset = i * stride;
    src[offset + 0 * stride] = v += block[0];
    src[offset + 1 * stride] = v += block[8];
    src[offset + 2 * stride] = v += block[16];
    src[offset + 3 * stride] = v += block[24];
    src[offset + 4 * stride] = v += block[32];
    src[offset + 5 * stride] = v += block[40];
    src[offset + 6 * stride] = v += block[48];
    src[offset + 7 * stride] = v + block[56];
    src++;
    block++;
}
}
