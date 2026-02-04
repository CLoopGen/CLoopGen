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
        for (int j = 0; j < 8; j++) {
            if (j == 7) {
                pix[j] = v + block[j];
            } else {
                pix[j] = v += block[j];
            }
        }
        pix += stride;
        block += 8;
    }
}
