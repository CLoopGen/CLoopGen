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



void loop(){
    uint32 val0, val1, val2;
    for (x = w; x-- > 0;) {
        val0 = (wp[0] >> 8) & 255;
        val1 = (wp[1] >> 8) & 255;
        val2 = (wp[2] >> 8) & 255;
        *cp++ = (val0 | (val1 << 8) | (val2 << 16) | (255U << 24));
        wp += samplesperpixel;
    }
}
