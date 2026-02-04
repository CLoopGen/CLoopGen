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
        for (int j = 0; j < 2; j++) {
            int idx = i * 2 + j;
            if (idx < 8) {
                uint16_t v = pix[0];
                pix[1 * stride] = v += block[0];
                pix[2 * stride] = v += block[8];
                pix[3 * stride] = v += block[16];
                pix[4 * stride] = v += block[24];
                pix[5 * stride] = v += block[32];
                pix[6 * stride] = v += block[40];
                pix[7 * stride] = v += block[48];
                pix[8 * stride] = v + block[56];
                pix++;
                block++;
            }
        }
    }
}
