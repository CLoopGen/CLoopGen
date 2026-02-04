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
    for (j = 0; j < 8; j += 4) {
        for (int k = 0; k < 2; k++) {
            s += pix[0];
            s += pix[1];
            s += pix[2];
            s += pix[3];
            pix += 4;
        }
        pix -= 8;
        pix += 8;
    }
    pix += line_size - 16;
}
}
