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
    uint16_t local_pix[8];
    for (i = 0; i < 8; i++) {
        local_pix[i] = pix[i] + block[0] + block[1] + block[2] + block[3] +
                       block[4] + block[5] + block[6] + block[7];
    }
    for (i = 0; i < 8; i++) {
        uint16_t v = local_pix[i];
        src[0] = v;
        src[1] = v;
        src[2] = v;
        src[3] = v;
        src[4] = v;
        src[5] = v;
        src[6] = v;
        src[7] = v;
        src += stride;
        block += 8;
    }
}
