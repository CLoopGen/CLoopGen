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
    uint32 step = (samplesperpixel == 3) ? 3 : 1;
    for (x = w; x >= 2; x -= 2) {
        *cp++ = ((uint32)((wp[0] >> 8) & 255) | 
                ((uint32)((wp[1] >> 8) & 255) << 8) | 
                ((uint32)((wp[2] >> 8) & 255) << 16) | 
                ((uint32)(255U << 24)));
        wp += step;

        *cp++ = ((uint32)((wp[0] >> 8) & 255) | 
                ((uint32)((wp[1] >> 8) & 255) << 8) | 
                ((uint32)((wp[2] >> 8) & 255) << 16) | 
                ((uint32)(255U << 24)));
        wp += step;
    }
    while (x-- > 0) {
        *cp++ = ((uint32)((wp[0] >> 8) & 255) | 
                ((uint32)((wp[1] >> 8) & 255) << 8) | 
                ((uint32)((wp[2] >> 8) & 255) << 16) | 
                ((uint32)(255U << 24)));
        wp += samplesperpixel;
    }
}
