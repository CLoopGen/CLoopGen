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
for (i = 0; i < 8; i++) {
    uint16_t v = pix[0];
    int offset = 0;
    for (int j = 1; j <= 8; j++) {
        if (j < 8) {
            v += block[offset];
            pix[j * stride] = v;
        } else {
            pix[j * stride] = v + block[offset];
        }
        offset += 8;
    }
    pix++;
    block++;
}
}
