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
        int offset = i * 8;
        src[0] = v += block[offset + 0];
        src[stride] = v += block[offset + 1];
        src[2*stride] = v += block[offset + 2];
        src[3*stride] = v += block[offset + 3];
        src[4*stride] = v += block[offset + 4];
        src[5*stride] = v += block[offset + 5];
        src[6*stride] = v += block[offset + 6];
        src[7*stride] = v + block[offset + 7];
        src++;
        block += 8;
    }
}
