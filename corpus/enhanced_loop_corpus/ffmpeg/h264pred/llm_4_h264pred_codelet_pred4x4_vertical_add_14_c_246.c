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
        if (block[0] >= 0) {
            uint16_t v = pix[0];
            v += block[0];
            pix[1 * stride] = v;
            if (block[4] < 100) {
                v += block[4];
                pix[2 * stride] = v;
            } else {
                pix[2 * stride] = pix[0]; // different path
            }
            pix[3 * stride] = v += block[8];
            pix[4 * stride] = v + block[12];
        } else {
            // Skip computation and zero out entries
            pix[1 * stride] = 0;
            pix[2 * stride] = 0;
            pix[3 * stride] = 0;
            pix[4 * stride] = 0;
        }
        pix++;
        block++;
    }
}
