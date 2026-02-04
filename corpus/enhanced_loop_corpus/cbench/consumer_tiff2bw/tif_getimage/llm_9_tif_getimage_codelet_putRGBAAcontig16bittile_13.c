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
    uint32 i;
    for (x = w; x > 0; x -= 2) {
        for (i = 0; i < 2 && x - i > 0; ++i) {
            *cp++ = ((uint32)(((wp[0]) >> 8) & 255) |
                     (uint32)(((wp[1]) >> 8) & 255) << 8 |
                     (uint32)(((wp[2]) >> 8) & 255) << 16 |
                     (uint32)(((wp[3]) >> 8) & 255) << 24);
            wp += samplesperpixel;
        }
    }
}
