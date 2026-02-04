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
    uint32 step = (w + 3) / 4; // Increase trip count and unroll loop by factor of 4
    for (x = 0; x < step; x++) {
        if (w-- > 0) {
            *cp++ = ((uint32)(((wp[0]) >> 8) & 255) | ((uint32)(((wp[1]) >> 8) & 255) << 8) | ((uint32)(((wp[2]) >> 8) & 255) << 16) | ((uint32)(255L << 24)));
            wp += samplesperpixel;
        }
        if (w-- > 0) {
            *cp++ = ((uint32)(((wp[0]) >> 8) & 255) | ((uint32)(((wp[1]) >> 8) & 255) << 8) | ((uint32)(((wp[2]) >> 8) & 255) << 16) | ((uint32)(255L << 24)));
            wp += samplesperpixel;
        }
        if (w-- > 0) {
            *cp++ = ((uint32)(((wp[0]) >> 8) & 255) | ((uint32)(((wp[1]) >> 8) & 255) << 8) | ((uint32)(((wp[2]) >> 8) & 255) << 16) | ((uint32)(255L << 24)));
            wp += samplesperpixel;
        }
        if (w-- > 0) {
            *cp++ = ((uint32)(((wp[0]) >> 8) & 255) | ((uint32)(((wp[1]) >> 8) & 255) << 8) | ((uint32)(((wp[2]) >> 8) & 255) << 16) | ((uint32)(255L << 24)));
            wp += samplesperpixel;
        }
    }
}
