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
    uint32 cache[4];
    for (x = w; x-- > 0;) {
        cache[0] = wp[0]; cache[1] = wp[1]; cache[2] = wp[2];
        *cp++ = ((uint32)((cache[0] >> 8) & 255) | 
                 ((uint32)((cache[1] >> 8) & 255) << 8) | 
                 ((uint32)((cache[2] >> 8) & 255) << 16) | 
                 ((uint32)(255UL << 24)));
        wp += samplesperpixel;
    }
}
