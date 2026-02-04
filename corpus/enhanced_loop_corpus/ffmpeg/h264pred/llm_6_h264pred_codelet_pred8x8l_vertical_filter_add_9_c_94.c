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
        temp[1] = v += block[8];
        temp[2] = v += block[16];
        temp[3] = v += block[24];
        temp[4] = v += block[32];
        temp[5] = v += block[40];
        temp[6] = v += block[48];
        temp[7] = v + block[56];
        for (int j = 0; j < 8; j++) {
            src[j * stride] = temp[j];
        }
        src++;
        block++;
    }
}
