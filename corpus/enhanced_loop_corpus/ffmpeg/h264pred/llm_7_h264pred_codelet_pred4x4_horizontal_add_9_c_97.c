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
uint16_t accumulator = 0;
for (i = 0; i < 4; i++) {
    uint16_t v = pix[-1] + accumulator;
    accumulator = v;
    pix[0] = accumulator += block[0];
    pix[1] = accumulator += block[1];
    pix[2] = accumulator += block[2];
    pix[3] = accumulator + block[3];
    accumulator = pix[3]; 
    pix += stride;
    block += 4;
}
}
