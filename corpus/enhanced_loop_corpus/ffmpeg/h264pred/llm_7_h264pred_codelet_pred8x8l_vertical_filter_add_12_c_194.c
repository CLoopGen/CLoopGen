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
        uint16_t acc = v;
        acc += block[0];   src[0 * stride] = acc;
        acc += block[8];   src[1 * stride] = acc;
        acc += block[16];  src[2 * stride] = acc;
        acc += block[24];  src[3 * stride] = acc;
        acc += block[32];  src[4 * stride] = acc;
        acc += block[40];  src[5 * stride] = acc;
        acc += block[48];  src[6 * stride] = acc;
        acc += block[56];  src[7 * stride] = acc;
        src++;
        block++;
    }
}
