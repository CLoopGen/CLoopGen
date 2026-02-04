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
for (i = 0; i < 8; i++) {
    for (j = 0; j < 16; j += 16) {
        s += pix[0]; s += pix[1]; s += pix[2]; s += pix[3];
        s += pix[4]; s += pix[5]; s += pix[6]; s += pix[7];
        s += pix[8]; s += pix[9]; s += pix[10]; s += pix[11];
        s += pix[12]; s += pix[13]; s += pix[14]; s += pix[15];
        pix += 16;
    }
    pix += line_size * 2 - 16;
}
}
