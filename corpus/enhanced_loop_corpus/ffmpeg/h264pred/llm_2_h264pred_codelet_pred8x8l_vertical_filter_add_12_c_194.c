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
    int offset = i * stride;
    src[offset + 0] = v += block[0];
    src[offset + 1] = v += block[8];
    src[offset + 2] = v += block[16];
    src[offset + 3] = v += block[24];
    src[offset + 4] = v += block[32];
    src[offset + 5] = v += block[40];
    src[offset + 6] = v += block[48];
    src[offset + 7] = v + block[56];
    block++;
}
}
