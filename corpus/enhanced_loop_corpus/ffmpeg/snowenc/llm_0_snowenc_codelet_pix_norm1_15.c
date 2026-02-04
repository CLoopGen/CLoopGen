#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix;
extern int line_size;
extern int w;
extern int s;
extern int i;
extern int j;
extern  uint32_t *sq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w * w; i++) {
    s += sq[pix[0]];
    pix++;
    if ((i + 1) % w == 0) {
        pix += line_size - w;
    }
}
}
