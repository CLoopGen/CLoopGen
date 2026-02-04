#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix;
extern int line_size;
extern int s;
extern int i;
extern int j;
extern  uint32_t *sq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; ++i) {
    for (j = 0; j < 16; j += 8) {
        register uint32_t x = *(uint32_t *)pix;
        uint8_t b0 = x & 255, b1 = (x >> 8) & 255;
        uint8_t b2 = (x >> 16) & 255, b3 = (x >> 24) & 255;
        if (b0 >= 16 || b1 >= 16) {
            s += sq[b0]; s += sq[b1];
        }
        if (b2 >= 16 || b3 >= 16) {
            s += sq[b2]; s += sq[b3];
        }
        x = *(uint32_t *)(pix + 4);
        b0 = x & 255; b1 = (x >> 8) & 255;
        b2 = (x >> 16) & 255; b3 = (x >> 24) & 255;
        if (b0 >= 16 || b1 >= 16) {
            s += sq[b0]; s += sq[b1];
        }
        if (b2 >= 16 || b3 >= 16) {
            s += sq[b2]; s += sq[b3];
        }
        pix += 8;
    }
    if (i % 2 == 0) {
        pix += line_size - 16;
    } else {
        pix += line_size - 16;
    }
}
}
