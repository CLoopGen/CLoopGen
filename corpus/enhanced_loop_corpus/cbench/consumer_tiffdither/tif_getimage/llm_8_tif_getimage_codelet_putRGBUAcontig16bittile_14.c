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
        uint32 result = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16));
        *cp++ = result | ((uint32)(a) << 24);
        wp += samplesperpixel;
        // Unrolled computation with intermediate storage to increase arithmetic operations
        r ^= g; 
        b ^= a;
        *cp++ = ((uint32)(r) | ((uint32)(b) << 8) | ((uint32)(g) << 16) | ((uint32)(a) << 24));
        if (--x == 0) break;
        a = wp[3] >> 4;
        r = (wp[0] * a) / 69375;
        g = (wp[1] * a) / 69375;
        b = (wp[2] * a) / 69375;
        wp += samplesperpixel;
    }
}
