#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef unsigned short uint16;

extern uint32 *cp;
extern uint32 x;
extern uint32 w;
extern int samplesperpixel;
extern uint16 *wp;
extern uint32 r;
extern uint32 g;
extern uint32 b;
extern uint32 a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = w; x-- > 0;) {
        a = wp[3] >> 4;
        r = (wp[0] * a) / 69375;
        g = (wp[1] * a) / 69375;
        b = (wp[2] * a) / 69375;
        uint32 rgba = ((r & 0xFF) | ((g & 0xFF) << 8) | ((b & 0xFF) << 16) | ((a & 0xFF) << 24));
        *cp++ = rgba;
        wp += samplesperpixel;
        // Additional arithmetic to increase computational intensity
        r = (r + g) ^ 0x5A5A;
        b = (b - a) & 0xFFFF;
        r = (r * 3 + 1) >> 1;
        g = (g * 3 + 1) >> 1;
        b = (b * 3 + 1) >> 1;
    }
}
