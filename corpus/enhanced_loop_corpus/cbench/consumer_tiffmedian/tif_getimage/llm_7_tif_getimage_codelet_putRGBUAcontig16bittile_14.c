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
    uint32 local_a, local_r, local_g, local_b;
    uint32 *local_cp = cp;
    uint16 *local_wp = wp;
    for (x = w; x-- > 0;) {
        local_a = local_wp[3] >> 4;
        local_r = (local_wp[0] * local_a) / 69375;
        local_g = (local_wp[1] * local_a) / 69375;
        local_b = (local_wp[2] * local_a) / 69375;
        *local_cp++ = ((uint32)(local_r) | ((uint32)(local_g) << 8) | ((uint32)(local_b) << 16) | ((uint32)(local_a) << 24));
        local_wp += samplesperpixel;
    }
    cp = local_cp;
    wp = local_wp;
}
