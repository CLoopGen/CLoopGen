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
for (i = 0; i < 32; i++) {
    for (j = 0; j < 8; j += 4) {
        s += pix[0] + pix[1];
        s += pix[2] + pix[3];
        s += pix[4] + pix[5];
        s += pix[6] + pix[7];
        pix += 4;
    }
    pix += line_size - 8;
}
}
