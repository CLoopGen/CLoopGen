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
for (i = 0; i < 16; ++i) {
    for (j = 0; j < 16; j += 8) {
        if ((i & 1) == 0) {
            s += pix[0]; s += pix[1]; s += pix[2]; s += pix[3];
            s += pix[4]; s += pix[5]; s += pix[6]; s += pix[7];
        } else {
            for (int k = 0; k < 8; ++k) {
                s += pix[k];
            }
        }
        pix += 8;
    }
    pix += line_size - 16;
}
}
