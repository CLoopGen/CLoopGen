#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *src;
extern  int16_t *block;
extern uint8_t pix[8];
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[8] = {0, 1, 2, 3, 4, 5, 6, 7};
for (i = 0; i < 8; i++) {
    uint8_t v = pix[i];
    v += block[indices[0]];
    src[indices[0]] = v;
    v += block[indices[1]];
    src[indices[1]] = v;
    v += block[indices[2]];
    src[indices[2]] = v;
    v += block[indices[3]];
    src[indices[3]] = v;
    v += block[indices[4]];
    src[indices[4]] = v;
    v += block[indices[5]];
    src[indices[5]] = v;
    v += block[indices[6]];
    src[indices[6]] = v;
    v += block[indices[7]];
    src[indices[7]] = v;
    src += stride;
    block += 8;
}
}
