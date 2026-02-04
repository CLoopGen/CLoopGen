#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern uint8_t *pix;
extern  int16_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        uint8_t v1 = pix[0];
        uint8_t v2 = v1 + block[0];
        uint8_t v3 = v2 + block[4];
        uint8_t v4 = v3 + block[8];
        pix[1 * stride] = v2;
        pix[2 * stride] = v3;
        pix[3 * stride] = v4;
        pix[4 * stride] = v4 + block[12];
        pix++;
        block++;
    }
}
