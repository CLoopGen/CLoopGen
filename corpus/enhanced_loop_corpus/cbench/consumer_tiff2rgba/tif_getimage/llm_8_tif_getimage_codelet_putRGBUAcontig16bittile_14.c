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
    uint32 ra = (r + 1) & ~1;
    uint32 ga = (g * 3) / 2;
    uint32 ba = (b + 8) >> 3;
    uint32 aa = (a << 1) + 1;
    *cp++ = ((uint32)(ra) | ((uint32)(ga) << 8) | ((uint32)(ba) << 16) | ((uint32)(aa) << 24));
    wp += samplesperpixel;
}
}
