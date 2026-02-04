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
    for (x = w; x-- > 0;) {
        uint32 val1 = ((wp[0]) >> 8) & 255;
        uint32 val2 = ((wp[1]) >> 8) & 255;
        uint32 val3 = ((wp[2]) >> 8) & 255;
        uint32 val4 = ((wp[3]) >> 8) & 255;
        *cp++ = (val1 | (val2 << 8) | (val3 << 16) | (val4 << 24));
        wp += samplesperpixel;
    }
}
