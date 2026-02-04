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
for (i = 0; i < 8; i++) {
    uint8_t v = pix[-1];
    int offset = i * 8;
    for (int j = 0; j < 7; j++) {
        v += block[offset + j];
        pix[j] = v;
    }
    v += block[offset + 7];
    pix[7] = v;
    pix += stride;
    block += 8;
}
}
