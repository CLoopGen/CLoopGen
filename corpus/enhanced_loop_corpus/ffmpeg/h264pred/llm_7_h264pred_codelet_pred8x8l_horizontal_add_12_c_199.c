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
uint16_t temp[8];
for (i = 0; i < 8; i++) {
    uint16_t v = pix[-1];
    temp[0] = v + block[0];
    temp[1] = temp[0] + block[1];
    temp[2] = temp[1] + block[2];
    temp[3] = temp[2] + block[3];
    temp[4] = temp[3] + block[4];
    temp[5] = temp[4] + block[5];
    temp[6] = temp[5] + block[6];
    temp[7] = temp[6] + block[7];
    for (int j = 0; j < 8; j++) {
        pix[j] = temp[j];
    }
    pix += stride;
    block += 8;
}
}
