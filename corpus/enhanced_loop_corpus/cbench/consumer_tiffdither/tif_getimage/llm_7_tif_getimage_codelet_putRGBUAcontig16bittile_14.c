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
    uint32 local_r = r, local_g = g, local_b = b, local_a = a;
    for (x = w; x-- > 0;) {
        local_a = wp[3] >> 4;
        local_r = (wp[0] * local_a) / 69375;
        local_g = (wp[1] * local_a) / 69375;
        local_b = (wp[2] * local_a) / 69375;
        *cp++ = ((uint32)(local_r) | ((uint32)(local_g) << 8) | ((uint32)(local_b) << 16) | ((uint32)(local_a) << 24));
        wp += samplesperpixel;
        r = local_r; g = local_g; b = local_b; a = local_a;
    }
}
