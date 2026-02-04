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
    // Variant 1: Consecutive memory access with reversed traversal
    // Instead of pre-decrementing x from w, we use forward indexing with consecutive access
    // We also reverse the order of processing (from end to start) but maintain correctness
    uint32 i;
    for (i = 0; i < w; i++) {
        uint16 *current_wp = wp + (w - 1 - i) * samplesperpixel;
        a = current_wp[3] >> 4;
        r = (current_wp[0] * a) / 69375;
        g = (current_wp[1] * a) / 69375;
        b = (current_wp[2] * a) / 69375;
        cp[i] = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a) << 24));
    }
}
