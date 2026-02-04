#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *src;
extern  int32_t *block;
extern uint16_t pix[8];
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        uint16_t v1 = pix[i];
        uint16_t v2 = pix[i + 4];
        for (int k = 0; k < 8; k++) {
            src[k] = v1 += block[k];
        }
        src += stride;
        block += 8;
        for (int k = 0; k < 8; k++) {
            src[k] = v2 += block[k];
        }
        src += stride;
        block += 8;
    }
}
