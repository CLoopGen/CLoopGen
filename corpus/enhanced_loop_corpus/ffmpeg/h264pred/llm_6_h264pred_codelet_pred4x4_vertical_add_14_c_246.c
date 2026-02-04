#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern uint16_t *pix;
extern  int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        uint16_t v = pix[0];
        uint16_t temp1 = v + block[0];
        uint16_t temp2 = temp1 + block[4];
        uint16_t temp3 = temp2 + block[8];
        uint16_t temp4 = temp3 + block[12];
        pix[1 * stride] = temp1;
        pix[2 * stride] = temp2;
        pix[3 * stride] = temp3;
        pix[4 * stride] = temp4;
        pix++;
        block++;
    }
}
