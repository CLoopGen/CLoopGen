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
    for (int j = 0; j < 4; j++) {
        v += block[j];
        pix[j] = v;
    }
    pix += stride;
    block += 4;
}
}
