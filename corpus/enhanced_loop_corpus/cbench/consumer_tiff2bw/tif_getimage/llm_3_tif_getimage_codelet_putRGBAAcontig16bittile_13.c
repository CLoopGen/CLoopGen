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
    // Variant 2: Strided array access — process every other pixel, then revisit (simulating cache-friendly strided pattern)
    uint32 half_w = w / 2;
    uint16 *wp_even = wp;
    uint16 *wp_odd = wp + samplesperpixel;

    // First pass: even indices
    for (x = half_w; x-- > 0;) {
        *cp++ = ((uint32)((wp_even[0] >> 8) & 255) | 
                 ((uint32)((wp_even[1] >> 8) & 255) << 8) | 
                 ((uint32)((wp_even[2] >> 8) & 255) << 16) | 
                 ((uint32)((wp_even[3] >> 8) & 255) << 24));
        wp_even += 2 * samplesperpixel;
    }

    // Second pass: odd indices
    for (x = w - half_w; x-- > 0;) {
        *cp++ = ((uint32)((wp_odd[0] >> 8) & 255) | 
                 ((uint32)((wp_odd[1] >> 8) & 255) << 8) | 
                 ((uint32)((wp_odd[2] >> 8) & 255) << 16) | 
                 ((uint32)((wp_odd[3] >> 8) & 255) << 24));
        wp_odd += 2 * samplesperpixel;
    }
}
