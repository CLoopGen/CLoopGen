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
    // Variant 1: Consecutive memory access with manual loop unrolling (stride-1 access)
    uint32 temp_w = w;
    for (x = temp_w; x > 0; x -= 2) {
        // Process two iterations at once with consecutive wp access
        if (x >= 1) {
            *cp++ = ((uint32)(((wp[0]) >> 8) & 255) | 
                     ((uint32)(((wp[1]) >> 8) & 255) << 8) | 
                     ((uint32)(((wp[2]) >> 8) & 255) << 16) | 
                     ((uint32)(((wp[3]) >> 8) & 255) << 24));
            wp += samplesperpixel;
        }
        if (x > 1) {
            *cp++ = ((uint32)(((wp[0]) >> 8) & 255) | 
                     ((uint32)(((wp[1]) >> 8) & 255) << 8) | 
                     ((uint32)(((wp[2]) >> 8) & 255) << 16) | 
                     ((uint32)(((wp[3]) >> 8) & 255) << 24));
            wp += samplesperpixel;
        }
    }
}
