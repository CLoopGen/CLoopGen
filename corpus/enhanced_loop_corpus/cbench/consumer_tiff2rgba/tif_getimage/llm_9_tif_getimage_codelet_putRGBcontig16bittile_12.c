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
    uint32 step = (w + 3) / 4;
    for (x = step; x-- > 0;) {
        for (int k = 0; k < 4 && (step * 4 - (x * 4 + k)) < w; ++k) {
            uint32 r = (wp[0] >> 8) & 255;
            uint32 g = (wp[1] >> 8) & 255;
            uint32 b = (wp[2] >> 8) & 255;
            *cp++ = r | (g << 8) | (b << 16) | (255U << 24);
            wp += samplesperpixel;
        }
    }
}
