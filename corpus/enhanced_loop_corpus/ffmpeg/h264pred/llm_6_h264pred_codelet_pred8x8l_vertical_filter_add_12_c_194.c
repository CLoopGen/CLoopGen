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
    uint16_t temp[8];
    for (i = 0; i < 8; i++) {
        uint16_t v = pix[i];
        temp[0] = v += block[0];
        temp[1] = temp[0] + block[8];
        temp[2] = temp[1] + block[16];
        temp[3] = temp[2] + block[24];
        temp[4] = temp[3] + block[32];
        temp[5] = temp[4] + block[40];
        temp[6] = temp[5] + block[48];
        temp[7] = temp[6] + block[56];
        src[0 * stride] = temp[0];
        src[1 * stride] = temp[1];
        src[2 * stride] = temp[2];
        src[3 * stride] = temp[3];
        src[4 * stride] = temp[4];
        src[5 * stride] = temp[5];
        src[6 * stride] = temp[6];
        src[7 * stride] = temp[7];
        src++;
        block++;
    }
}
