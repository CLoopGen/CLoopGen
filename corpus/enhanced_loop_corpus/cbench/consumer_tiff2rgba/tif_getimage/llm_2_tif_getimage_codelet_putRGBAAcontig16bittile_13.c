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
    for (x = w; x-- > 0;) {
        uint32 val = 0;
        for (int i = 0; i < 4; ++i) {
            val |= (uint32)(((wp[i * samplesperpixel]) >> 8) & 255) << (i * 8);
        }
        *cp++ = val;
        wp += samplesperpixel;
    }
}
