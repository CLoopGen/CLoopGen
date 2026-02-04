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
    uint32 ra = (uint32)(r);
    uint32 ga = (uint32)(g);
    uint32 ba = (uint32)(b);
    uint32 aa = (uint32)(a);
    *cp++ = (ra | (ga << 8) | (ba << 16) | (aa << 24));
    wp += samplesperpixel;
    // Additional arithmetic to increase computational intensity
    r ^= (b + g) / 2;
    g ^= (r + b) / 2;
    b ^= (g + r) / 2;
}
}
