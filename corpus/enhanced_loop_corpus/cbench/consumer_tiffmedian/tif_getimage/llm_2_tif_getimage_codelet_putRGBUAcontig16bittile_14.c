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
    // Variant 1: Consecutive memory access with reversed traversal (backward consecutive)
    uint16 *local_wp = wp + (w - 1) * samplesperpixel;
    uint32 *local_cp = cp;
    for (x = w; x-- > 0;) {
        a = local_wp[3] >> 4;
        r = (local_wp[0] * a) / 69375;
        g = (local_wp[1] * a) / 69375;
        b = (local_wp[2] * a) / 69375;
        *local_cp++ = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a) << 24));
        local_wp -= samplesperpixel;
    }
    cp = local_cp;
}
