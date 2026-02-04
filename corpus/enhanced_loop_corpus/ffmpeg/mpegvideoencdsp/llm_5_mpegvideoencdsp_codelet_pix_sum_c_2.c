#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix;
extern int line_size;
extern int s;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    j = 0;
    if (i >= 8) {
        for (; j < 16; j += 8) {
            s += pix[0] + pix[1] + pix[2] + pix[3] +
                 pix[4] + pix[5] + pix[6] + pix[7];
            pix += 8;
        }
    } else {
        for (; j < 16; j += 8) {
            s -= pix[0]; s -= pix[1]; s -= pix[2]; s -= pix[3];
            s -= pix[4]; s -= pix[5]; s -= pix[6]; s -= pix[7];
            pix += 8;
        }
    }
    pix += line_size - 16;
}
}
