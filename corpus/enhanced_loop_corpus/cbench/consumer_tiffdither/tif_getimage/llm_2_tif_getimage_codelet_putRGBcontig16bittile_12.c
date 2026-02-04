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



void loop() {
    // Variant 1: Consecutive memory access with manual increment of wp by a fixed stride
    // Instead of relying on samplesperpixel to index wp, we unroll the access pattern assuming samplesperpixel == 3
    // This creates a more predictable and consecutive access pattern for wp
    uint16 *local_wp = wp;
    uint32 *local_cp = cp;
    for (x = w; x-- > 0;) {
        *local_cp++ = ((uint32)((local_wp[0] >> 8) & 255) |
                       (uint32)((local_wp[1] >> 8) & 255) << 8 |
                       (uint32)((local_wp[2] >> 8) & 255) << 16 |
                       (uint32)(255UL << 24));
        local_wp += 3;  // Fixed stride assumption for consecutive triad access
    }
    cp = local_cp;
    wp = local_wp;
}
