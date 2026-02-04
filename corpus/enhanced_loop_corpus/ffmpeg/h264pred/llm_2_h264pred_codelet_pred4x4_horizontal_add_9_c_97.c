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
    uint16_t v = pix[-1];
    int32_t *b = &block[0];
    pix[0] = v += b[0];
    pix[1] = v += b[1];
    pix[2] = v += b[2];
    pix[3] = v + b[3];
    pix += stride;
    block += 4;
}
}
