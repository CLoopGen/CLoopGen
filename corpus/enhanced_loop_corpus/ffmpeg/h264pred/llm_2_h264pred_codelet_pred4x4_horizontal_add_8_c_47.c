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
    uint8_t v = pix[-1];
    int idx = i * 4;
    pix[0] = v += block[idx + 0];
    pix[1] = v += block[idx + 1];
    pix[2] = v += block[idx + 2];
    pix[3] = v + block[idx + 3];
    pix += stride;
}
}
