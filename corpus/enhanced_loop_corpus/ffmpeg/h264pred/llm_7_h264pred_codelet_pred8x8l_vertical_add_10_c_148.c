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
    for (i = 0; i < 8; i++) {
        uint16_t v = pix[0];
        uint16_t temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8;

        temp1 = v + block[0];
        pix[1 * stride] = temp1;
        temp2 = temp1 + block[8];
        pix[2 * stride] = temp2;
        temp3 = temp2 + block[16];
        pix[3 * stride] = temp3;
        temp4 = temp3 + block[24];
        pix[4 * stride] = temp4;
        temp5 = temp4 + block[32];
        pix[5 * stride] = temp5;
        temp6 = temp5 + block[40];
        pix[6 * stride] = temp6;
        temp7 = temp6 + block[48];
        pix[7 * stride] = temp7;
        temp8 = temp7 + block[56];
        pix[8 * stride] = temp8;

        pix++;
        block++;
    }
}
