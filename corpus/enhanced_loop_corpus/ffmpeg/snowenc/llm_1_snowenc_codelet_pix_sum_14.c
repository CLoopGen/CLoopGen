#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix;
extern int line_size;
extern int w;
extern int h;
extern int s;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h * w; i++) {
    s += pix[0];
    pix++;
    if ((i + 1) % w == 0) {
        pix += line_size - w;
    }
}
}
