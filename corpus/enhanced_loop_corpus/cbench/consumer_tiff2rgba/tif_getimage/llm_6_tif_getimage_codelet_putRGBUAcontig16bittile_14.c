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
    uint32 temp_a, temp_r, temp_g, temp_b;
    for (x = w; x-- > 0;) {
        temp_a = wp[3] >> 4;
        temp_r = (wp[0] * temp_a) / 69375;
        temp_g = (wp[1] * temp_a) / 69375;
        temp_b = (wp[2] * temp_a) / 69375;
        a = temp_a;
        r = temp_r;
        g = temp_g;
        b = temp_b;
        *cp++ = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a) << 24));
        wp += samplesperpixel;
    }
}
