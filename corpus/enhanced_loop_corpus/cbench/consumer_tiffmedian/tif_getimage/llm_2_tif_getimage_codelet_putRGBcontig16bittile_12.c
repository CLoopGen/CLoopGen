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
    // Variant 1: Consecutive memory access with pre-increment indexing
    // Instead of post-decrement logic, we use forward indexing with consecutive access.
    // We calculate the total iterations first and then access wp in increasing order.
    uint32 temp_w = w;
    for (x = 0; x < temp_w; x++) {
        uint16* current_wp = wp + x * samplesperpixel;
        *cp++ = ((uint32)((current_wp[0] >> 8) & 255)) |
                ((uint32)((current_wp[1] >> 8) & 255) << 8) |
                ((uint32)((current_wp[2] >> 8) & 255) << 16) |
                ((uint32)(255UL << 24));
    }
}
