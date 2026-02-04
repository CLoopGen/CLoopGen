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
for (i = 0; i < 256; i++) {
    s += pix[0];
    s += pix[1];
    s += pix[2];
    s += pix[3];
    s += pix[4];
    s += pix[5];
    s += pix[6];
    s += pix[7];
    pix += 8;
    if ((i + 1) % 16 == 0) {
        pix += line_size - 16;
    }
}
}
