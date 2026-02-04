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
ptrdiff_t s = stride;
for (i = 0; i < 4; i++) {
    uint16_t v = pix[i * s - 1];
    pix[i * s + 0] = v += block[i * 4 + 0];
    pix[i * s + 1] = v += block[i * 4 + 1];
    pix[i * s + 2] = v += block[i * 4 + 2];
    pix[i * s + 3] = v + block[i * 4 + 3];
}
}
