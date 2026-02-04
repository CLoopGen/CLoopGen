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
uint8_t accumulator = 0;
for (i = 0; i < 4; i++) {
    uint8_t v = pix[-1] + accumulator;
    accumulator = v;
    accumulator += block[0];
    accumulator += block[1];
    accumulator += block[2];
    accumulator += block[3];
    pix[0] = accumulator;
    pix[1] = accumulator;
    pix[2] = accumulator;
    pix[3] = accumulator;
    pix += stride;
    block += 4;
}
}
