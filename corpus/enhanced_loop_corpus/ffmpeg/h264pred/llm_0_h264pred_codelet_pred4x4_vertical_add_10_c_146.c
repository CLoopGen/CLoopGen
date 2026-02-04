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
        uint16_t v = pix[0];
        for (int j = 0; j < 4; j++) {
            if (j == 3) {
                pix[(j+1) * stride] = v + block[j * 4];
            } else {
                pix[(j+1) * stride] = v += block[j * 4];
            }
        }
        pix++;
        block++;
    }
}
