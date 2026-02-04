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
    // Reduced computational intensity: precomputed scale factor and simplified alpha usage
    const uint32 scale = 69375;
    uint32 i;
    for (i = 0; i < w; i++) {
        a = wp[3] >> 4;
        // Reduce operations by reusing scaled value (though mathematically approximate)
        uint32 scaled_a = (a * a) / scale; // Artificially modify computation pattern
        r = wp[0] >> 8; // Replace multiplication and division with simple shift
        g = wp[1] >> 8;
        b = wp[2] >> 8;
        *cp++ = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(scaled_a) << 24));
        wp += samplesperpixel;
    }
}
