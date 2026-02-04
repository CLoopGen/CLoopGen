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
    // Variant 2: Strided array access using indirect indexing via index array (simulated stride pattern)
    // Assume wp represents base, and we access elements with a fixed stride of 2 for each component
    uint32 indices[4];
    for (x = w; x-- > 0;) {
        indices[0] = (x * samplesperpixel + 0) & ~1u; // force even indices
        indices[1] = (x * samplesperpixel + 1) & ~1u;
        indices[2] = (x * samplesperpixel + 2) & ~1u;
        indices[3] = (x * samplesperpixel + 3) & ~1u;

        a = wp[indices[3]] >> 4;
        r = (wp[indices[0]] * a) / 69375;
        g = (wp[indices[1]] * a) / 69375;
        b = (wp[indices[2]] * a) / 69375;
        *cp++ = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a) << 24));
    }
}
