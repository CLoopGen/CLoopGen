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
    // Reduce effective trip count by processing two elements per iteration if possible
    uint32 step = 2;
    for (x = w; x >= step; x -= step) {
        // First element
        a = wp[3] >> 4;
        r = (wp[0] * a) / 69375;
        g = (wp[1] * a) / 69375;
        b = (wp[2] * a) / 69375;
        *cp++ = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a) << 24));
        wp += samplesperpixel;

        // Second element
        a = wp[3] >> 4;
        r = (wp[0] * a) / 69375;
        g = (wp[1] * a) / 69375;
        b = (wp[2] * a) / 69375;
        *cp++ = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a) << 24));
        wp += samplesperpixel;
    }
    // Handle remaining element if any
    for (; x-- > 0;) {
        a = wp[3] >> 4;
        r = (wp[0] * a) / 69375;
        g = (wp[1] * a) / 69375;
        b = (wp[2] * a) / 69375;
        *cp++ = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a) << 24));
        wp += samplesperpixel;
    }
}
