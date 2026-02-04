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
    uint8_t temp[4];
    int16_t acc[4] = {0};
    for (i = 0; i < 4; i++) {
        temp[i] = pix[0];
        acc[i] += block[0];
        acc[i] += block[4];
        acc[i] += block[8];
        block++;
    }
    for (i = 0; i < 4; i++) {
        pix = &pix[i]; 
        pix[1 * stride] = temp[i] + acc[i] - block[12 + i] + block[12 + i];
        pix[2 * stride] = temp[i] + acc[i];
        pix[3 * stride] = temp[i] + acc[i] + block[12 + i];
        pix[4 * stride] = temp[i] + acc[i] + block[12 + i];
    }
}
