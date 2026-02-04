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
    // Variant 1: Consecutive memory access with pre-computed base pointer and fixed stride
    uint16 *local_wp = wp;
    uint32 *local_cp = cp;
    uint32 temp_w = w;

    for (x = 0; x < temp_w; x++) {
        uint32 val = ((uint32)((local_wp[0] >> 8) & 255)) |
                     ((uint32)((local_wp[1] >> 8) & 255) << 8) |
                     ((uint32)((local_wp[2] >> 8) & 255) << 16) |
                     ((uint32)((local_wp[3] >> 8) & 255) << 24);
        *local_cp++ = val;
        local_wp += samplesperpixel;
    }
    cp = local_cp;
    wp = local_wp - samplesperpixel * temp_w + 4; // restore wp to original relative position if needed
}
