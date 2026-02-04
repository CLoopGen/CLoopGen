#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef unsigned short uint16;

extern uint32 *cp;
extern uint32 x;
extern uint32 w;
extern int samplesperpixel;
extern uint16 *wp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    uint32 temp1, temp2, temp3, temp4;
    for (x = w; x-- > 0;) {
        temp1 = ((uint32)((wp[0]) >> 8) & 255);
        temp2 = ((uint32)((wp[1]) >> 8) & 255) << 8;
        temp3 = ((uint32)((wp[2]) >> 8) & 255) << 16;
        temp4 = ((uint32)((wp[3]) >> 8) & 255) << 24;
        *cp++ = temp1 | temp2 | temp3 | temp4;
        wp += samplesperpixel;
    }
}
