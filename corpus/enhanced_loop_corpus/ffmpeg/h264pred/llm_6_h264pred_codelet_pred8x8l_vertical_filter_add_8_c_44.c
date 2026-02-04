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
        uint8_t temp = v;
        src[0 * stride] = temp = (uint8_t)(temp + block[0]);
        src[1 * stride] = temp = (uint8_t)(temp + block[8]);
        src[2 * stride] = temp = (uint8_t)(temp + block[16]);
        src[3 * stride] = temp = (uint8_t)(temp + block[24]);
        src[4 * stride] = temp = (uint8_t)(temp + block[32]);
        src[5 * stride] = temp = (uint8_t)(temp + block[40]);
        src[6 * stride] = temp = (uint8_t)(temp + block[48]);
        src[7 * stride] = (uint8_t)(temp + block[56]); // Break WAW by not assigning to temp
        src++;
        block++;
    }
}
