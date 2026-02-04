#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef unsigned short uint16;

extern uint32 *cp;
extern uint32 x;
extern uint32 w;
extern int samplesperpixel;
extern uint16 *wp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed traversal
    // Traverse wp in reverse with a fixed stride based on samplesperpixel.
    // This changes access pattern from forward sequential to backward strided.
    for (x = w; x > 0; x--) {
        int index = (x - 1) * samplesperpixel;
        uint16* rev_wp = wp + index;
        *cp++ = ((uint32)((rev_wp[0] >> 8) & 255)) |
                ((uint32)((rev_wp[1] >> 8) & 255) << 8) |
                ((uint32)((rev_wp[2] >> 8) & 255) << 16) |
                ((uint32)(255UL << 24));
    }
}
